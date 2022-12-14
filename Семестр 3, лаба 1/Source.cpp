#include<iostream>
#include<stdexcept>
#include<iomanip>

#pragma once


class Image {
private:
	int _l, _w;
	bool** _px;

public:
	Image() : _l(0), _w(0) {
		_px = new bool* [_l];
		for (int i = 0; i < _l; i++) {
			_px[i] = new bool[_w];
		}
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] = false;
			}
		}
	}

	Image(int l, int w, bool value) {
		if (l <= 0 || w <= 0) throw std::logic_error("incorrect image sizes");
		_l = l;
		_w = w;
		_px = new bool* [_l];
		for (int i = 0; i < _l; i++) {
			_px[i] = new bool[_w];
		}
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] = value;
			}
		}
	}

	Image(const Image& another) : Image(another._l, another._w, 0) {
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] = another._px[i][j];
			}
		}
	}

	~Image() {
		for (int i = 0; i < _l; i++) {
			delete _px[i];
		}
		delete[] _px;
	}

	//Перегруженние операторов
	bool& operator()(int l, int w) const {
		if (l < 0 || l > _l || w < 0 || w > _w) throw std::out_of_range("invalid index");
		return _px[l][w];
	}

	Image operator+(const Image& obj) {
		if (_l != obj._l || _w != obj._w) throw std::logic_error("size mismatch");
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] = _px[i][j] || obj._px[i][j];
			}
		}
		return *this;
	}

	Image operator*(const Image& obj) const {
		if (_l != obj._l || _w != obj._w) throw std::logic_error("size mismatch");
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				temp_px(i, j) = _px[i][j] && obj._px[i][j];
			}
		}
		return temp_px;
	}

	Image operator+(const bool value) {
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] || value ?
					_px[i][j] = true :
					_px[i][j] = false;
			}
		}
		return *this;
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

	Image operator*(const bool value) {
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				_px[i][j] && value ?
					_px[i][j] = true :
					_px[i][j] = false;
			}
		}
		return *this;
	}

	Image operator!() {
		Image temp_px(*this);
		for (int i = 0; i < _l; i++) {
			for (int j = 0; j < _w; j++) {
				temp_px(i, j) = !_px[i][j];
			}
		}
		return temp_px;
	}

	friend std::ostream& operator<<(std::ostream& out, const Image& obj) {
		for (int i = 0; i < obj._l; i++) {
			for (int j = 0; j < obj._w; j++) {
				if (obj._px[i][j])
					out << "\t" << "1";
				else out << "\t" << ".";
			}
			out << "\n";
		}
		system("pause");
		return out;
	}

	friend double fullness(const Image& obj) {
		double empty = 0, full = 0;
		for (int i = 0; i < obj._l; i++) {
			for (int j = 0; j < obj._w; j++) {
				empty++;
				if (obj._px[i][j]) {
					full++;
					continue;
				}
			}
		}
		return full / empty;
	}

	Image creating_rectangle(int x1, int y1, int x2, int y2) {
		if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) throw std::logic_error("coordinates mismatch");
		int i = x1, j = y1;
		if (_px[i][j] != true) {
			while (i < x2) {
				_px[i][j] = true;
				++i;
			}
			while (j < y2) {
				_px[i][j] = true;
				++j;
			}
			while (i >= x1) {
				_px[i][j] = true;
				--i;
			}
			while (j >= y1) {
				_px[i][j] = true;
				--j;
			}
			return *this;
		}
	}
};
