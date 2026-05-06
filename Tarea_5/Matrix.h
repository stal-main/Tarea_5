#pragma once

#include <stdexcept>

using std::runtime_error;

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

	int getRows() {

	}

	int getColumns() {

	}

	void setAll(E value) {

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

	}
};

