#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "lineTotals.h"

using namespace std;

/* moved to seperate file for testing

int LineTotals(vector <vector <int> > &row, vector <vector <int> > &col, unsigned i, unsigned j){
	int total=0;
	for(vector<int>::size_type k = 0; k < row.at(i).size(); ++k){//cycles across row of first and down column of second matrix
		total += row.at(i).at(k) * col.at(k).at(j);	//building the total for a given position of the resulting matrix
	}
	return total;
}*/

int main() {
   vector <vector <int> > matrix1;
   vector <vector <int> > matrix2;
   vector <vector <int> > result;	//first, second, and resulting matrix
   int l1, c1, l2, c2;				//storage for matrix dimensions
   vector<int>::size_type i = 0;
   vector<int>::size_type j = 0;//loop building blocks
   string matrixData;
   istringstream dimensions;
   label1:
   //cin >> l1 >> c1 >> l2 >> c2;		//get inputs of matrix dimensions
   getline(cin, matrixData);
   dimensions.str(matrixData);
   dimensions >> l1 >> c1 >> l2 >> c2;
   if(l1 != c2){
	   cerr << "These matricies cannot be multiplied." << endl;	//check matrix compatability
	   goto label1;						//try again on line 22 if incompatible
   }
   
   matrix1.resize(l1);
   matrix2.resize(l2);   
   for(i = 0; i < matrix1.size(); ++i){//build and fill first matrix
	   matrix1.at(i).resize(c1);
	  // matrix2.at(i).resize(c2);
	   for( j = 0; j < matrix1.at(i).size(); ++j){
		   cin >> matrix1.at(i).at(j);
		//   fill2 >> matrix2.at(i).at(j);
	   }
   }
   for( i = 0; i < matrix2.size(); ++i){//build and fill second matrix
		matrix2.at(i).resize(c2);
	   for( j = 0; j < matrix2.at(i).size(); ++j){
		   cin >> matrix2.at(i).at(j);
		}
   }
   result.resize(l1);
	for(i = 0; i < result.size(); ++i){//build result matrix
		result.at(i).resize(c2);
		for(j = 0; j < result.at(i).size(); ++j){//use function to fill results
			result.at(i).at(j) = LineTotals(matrix1, matrix2, i, j);
			cout << result.at(i).at(j) << " ";//output simultaneously
		}
		cout << endl;//endline after each row
	}
	return 0;
}
