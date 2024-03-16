#include <list>
#include <iostream>

using namespace std;

// Print SpreadSheet Method
void printMatrix(const list<list<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

// Add Row Method
void addRow(list<list<int>>& matrix, const list<int>& newRow) {
    matrix.push_back(newRow);
}

// Delete Row Method
void deleteRow(list<list<int>>& matrix, int rowIndex) {
    auto it = matrix.begin();
    advance(it, rowIndex);
    matrix.erase(it);
}

int main() {
    list<list<int>> spreadsheet = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Initial spreadsheet:" << endl;
    printMatrix(spreadsheet);

    // Add Row

    list<int> newRow = { 0, 4, 1 };
    addRow(spreadsheet, newRow);

    cout << "\nSpreadsheet after adding a new row:" << endl;
    printMatrix(spreadsheet);

    // Delete row

    int rowToDelete = 1; 
    deleteRow(spreadsheet, rowToDelete);

    cout << "\nSpreadsheet after deleting row " << rowToDelete + 1<< ":" << endl;
    printMatrix(spreadsheet);

    return 0;
}
