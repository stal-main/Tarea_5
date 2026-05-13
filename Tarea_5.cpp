
#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

void printMenu() {

    cout << "\n------------\n";

    cout << "Matrix Menu\n";

    cout << "------------\n";

    cout << "\n1. Get value\n";
    cout << "2. Update value\n";
    cout << "3.Get rows\n";
    cout << "4.Get columns\n";
    cout << "5.Update all values\n";
    cout << "6.Transpose matrix\n";
    cout << "7.Add row\n";
    cout << "8.Add column\n";
    cout << "9.Remove row\n";
    cout << "10.Remove column\n";
    cout << "11.Load random values (0-99)\n";
    cout << "0. Exit\n";

    cout << "Choose and option: ";
}

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int rows;

    cout << "Enter number of rows: ";

    cin >> rows;

    int cols;

    cout << "Enter number of columns: ";

    cin >> cols;

    Matrix<int>* m = nullptr;

    try {

        m = new Matrix<int>(rows, cols);
    }

    catch (const runtime_error& e) {

        cout << "Error creating matrix: " << e.what() << endl;
        return 1;
    }

    cout << "Matrix created (" << rows << " x " << cols << ")\n";

    int option = -1;

    while (option != 0) {

        cout << "Current Matrix:\n";

        m->print();

        printMenu();

        cin >> option;

        try {

            if (option == 0) {

                cout << "Exiting";
            }

            else if (option == 1) {

                int r;

                int c;

                cout << "Enter row: "; 

                cin >> r;

                cout << "Enter column: ";

                cin >> c;

                cout << "Value at (" << r << ", " << c << "): " << m->getValue(r, c) << endl;
            }

            else if (option == 2) {

                int r;

                int c;

                int val;

                cout << "Enter row: ";

                cin >> r;

                cout << "Enter column: ";

                cin >> c;

                cout << "Enter value";

                cin >> val;

                m->setValue(r, c, val);

                cout << "Value set\n";
            }

            else if (option == 3) {

                cout << "Rows: " << m->getRows() << endl;

            }

            else if (option == 4) {

                cout << "Columns: " << m->getColumns() << endl;
            }

            else if (option == 5) {

                int val;

                cout << "Enter value to fill all cells: ";

                cin >> val;

                m->setAll(val);
                cout << "All cells set to " << val << "\n";
            }

            else if (option == 6) {

                m->transpose();

                cout << "Matrix transposed\n";
            }

            else if (option == 7) {

                int val;

                cout << "Enter value for new row: ";

                cin >> val;

                m->addRow(val);

                cout << "Row added";

            }

            else if (option == 8) {

                int val;

                cout << "Enter value for new column: ";

                cin >> val;

                m->addColumn(val);

                cout << "Column added";

            }

            else if (option == 9) {

                int r;

                cout << "Enter row to remove: ";

                cin >> r;

                m->removeRow(r);

                cout << "Row" << r << " removed\n";

            }

            else if (option == 10) {

                int c;

                cout << "Enter column to remove; ";

                cin >> c;

                m->removeColumn(c);

                cout << "Column" << c << " removed\n";

            }

            else if (option == 11) {

                for (int i = 0; i < m->getRows(); i++) {

                    for (int j = 0; j < m->getColumns(); j++) {

                        m->setValue(i, j, rand() % 100);
                    }
                }

                cout << "Matrix loaded with random values\n";
            }

            else {

                cout << "invalid option, try again\n";
            }
        }

        catch (const runtime_error& e) {

            cout << "\nError, operation could not be perfomed: " << e.what() << endl;
        }
    }

    delete m;

    return 0;
}

