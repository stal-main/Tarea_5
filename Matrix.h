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

		if (rows < 1 || columns < 1) {

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

		if (r < 0 || r >= rows) {

			throw runtime_error("Invalid row");
		}

		if (c < 0 || c >= columns) {

			throw runtime_error("Invalid column");
		}

		matrix[r][c] = value;
	}

	E getValue(int r, int c, E value) {

		if (r < 0 || r >= rows) {

			throw runtime_error("Invalid row");
		}

		if (c < 0 || c >= columns) {

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

		E** newMatrix = new E * [columns];

		for (int i = 0; i < columns; i++) {

			newMatrix[i] = new E[rows];

			for (int j = 0; j < rows; j++) {

				newMatrix[i][j] = matrix[j][i];
			}

		}

		for (int i = 0; 0 < rows; i++) {

			delete[] matrix[i];
		}

		delete[] matrix;

		matrix = newMatrix;
		
		int temp = rows;

		rows = columns;

		columns = temp;

	}

	void addRow(E value) {

		E** newMatrix = new E * [rows + 1];

		for (int i = 0; i < rows; i++) {

			newMatrix[i] = matrix[i];
		}

		newMatrix[rows] = new E[columns];

		for (int j; j < columns; j++) {

			newMatrix[rows][j] = value;
		}

		delete[] matrix;

		matrix = newMatrix;

		rows++;
	}

	void addColumn(E value) {

		transpose();

		addRow(value);

		transpose();

	}

	void removeRow(int row) {

		if (row < 0 || row >= rows) {

			throw runtime_error("Invalid row");
		}

		delete[] matrix[row];

		E** newMatrix = new E * [rows - 1];

		int k = 0;

		for (int i = 0; i < rows; i++) {

			if (i != row) {

				newMatrix[k++] = matrix[i];
			}
		}

		delete[] matrix;

		matrix = newMatrix;

		rows--;
	}

	void removeColumn(int col) {

		if (col < 0 || col >= columns) {

			throw runtime_error("Invalid column");
		}

		transpose();

		removeRow(col);

		transpose();

		columns--;
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

