#include<iostream>
#include<stdexcept>



using namespace std;

class Image {
private:
	int _l, _w;
	bool** px;

public:
	Image() : _l(0), _w(0) {
		px = new bool* [_l];
		for (int i = 0; i < _l; i++) {
			px[i] = new bool[_w];
		}
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				px[i][j] = false;
			}
		}
	}
	Image(int l, int w, bool value = false) {
		if(l < 0 || w < 0) throw(std::logic_error("incorrect image sizes"));
		_l = l;
		_w = w;
		px = new bool* [_l];
		for (int i = 0; i < _l; i++) {
			px[i] = new bool[_w];
		}
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				px[i][j] = value;
			}
		}
	}
	Image(const Image& another) : Image(another._l, another._w, 0) {
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				px[i][j] = another.px[i][j];
			}
		}
	}
	~Image() {
		for (int i = 0; i < _l; i++) {
			delete px[i];
		}
		delete[] px;
	}
	//Перегруженные операторы
	bool& operator()(int l, int w) const {
		if(l < 0 || l > _l || w < 0 || w > _w) throw std::out_of_range("invalid index");
		return px[l][w];
	}
	Image operator+(const Image& obj) const {
		if(_l != obj._l || _w != obj._w) throw std::logic_error("size mismatch");
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				temp_px(i, j) = px[i][j] || obj.px[i][j];
			}
		}
		return temp_px;
	}
	Image operator*(const Image& obj) const {
		if (_l != obj._l || _w != obj._w) throw std::logic_error("size mismatch");
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				temp_px(i, j) = px[i][j] && obj.px[i][j];
			}
		}
		return temp_px;
	}
	friend Image operator+(const bool value, const Image& obj) {
		Image temp_px(obj);
		for (int i = 0; i < obj._l; i++) {
			for (int j = 0; j < obj._w; j++) {
				temp_px(i, j) || value ?
					temp_px(i, j) = true :
					temp_px(i, j) = false;
			}
		}
		return temp_px;
	}
	friend Image operator*(const bool value, const Image& obj) {
		Image temp_px(obj);
		for (int i = 0; i < obj._l; i++) {
			for (int j = 0; j < obj._w; j++) {
				temp_px(i, j) && value ?
					temp_px(i, j) = true :
					temp_px(i, j) = false;
			}
		}
		return temp_px;
	}
	Image operator!() {
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				temp_px(i, j) = !px[i][j];
			}
		}
		return temp_px;
	}
	friend std::ostream& operator<<(std::ostream& out, const Image& obj);
	Image creating_rectangle(int x1, int y1, int x2, int y2) {
		for (int i = x1;;) {
			for (int j = y1; j < y2; j++) {
				px[i][j] = true;
			}
		}
		for (int i = x2;;) {
			for (int j = y1; j < y2; j++) {
				px[i][j] = true;
			}
		}
		for (int j = y1 + 1;;) {
			for (int i = x1; i < x2 - 1; i++) {
				px[i][j] = true;
			}
		}
		for (int j = y2 + 1;;) {
			for (int i = x1; i < x2 - 1; i++) {
				px[i][j] = true;
			}
		}
	}
};

std::ostream& operator<<(std::ostream& out, const Image& obj) {
	for (int i = 0; i < obj._l; i++) {
		for (int j = 0; j < obj._w; j++) {
			if(obj.px[i][j] == true) out << "\t" << "1";
			else out << "\t" << ".";
		}
		out << "\n";
	}
	system("pause");
	return out;
}