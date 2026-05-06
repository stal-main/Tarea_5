#pragma once

#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>

class Matrix {

private:

	E** matrix;

	int rows;

	int columns;

public:

	Matrix(int rows, int columns) {

		if (rows < 1 and columns < 1) {

			throw runtime_error("Invalid size");
		}

		matrix = new E * [rows];

		for (int i = 0; i < rows; i++) {

			matrix[i] = new E[columns];
		}

		this->rows = rows;

		this->columns = columns;

	}

	~Matrix() {

		for (int i = 0; i < rows; i++) {

			delete[] matrix[i];
		}

		delete[] matrix;

	}

	void setValue(int r, int c, E value) {

		if (r < 0 and r >= rows) {

			throw runtime_error("Invalid row");
		}

		if (c < 0 and c >= columns) {

			throw runtime_error("Invalid column");
		}

		matrix[r][c] = value;
	}

	E getValue(int r, int c, E value) {

		if (r < 0 and r >= rows) {

			throw runtime_error("Invalid row");
		}

		if (c < 0 and c >= columns) {

			throw runtime_error("Invalid column");
		}

		return matrix[r][c];

	}

	int getRows() {

		return rows;
	}

	int getColumns() {

		return columns;
	}

	void setAll(E value) {

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < columns; j++) {

				matrix[i][j] = value;

			}
		}
	}

	void transpose() {

	}

	void addRow(E value) {

	}

	void addColumn(E value) {

	}

	void removeRow(int row) {

	}

	void removeColumns(int columns) {

	}

	void print() {

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < columns; j++) {

				cout << matrix[i][j] << "\t";
			}

			cout << endl;
		}
	}
};

