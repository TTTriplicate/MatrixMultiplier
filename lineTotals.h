#ifndef LINETOTALS_H
#define LINETOTALS_H

int LineTotals(vector <vector <int> > &row, vector <vector <int> > &col, unsigned i, unsigned j){
	int total=0;
	for(vector<int>::size_type k = 0; k < row.at(i).size(); ++k){//cycles across row of first and down column of second matrix
		total += row.at(i).at(k) * col.at(k).at(j);	//building the total for a given position of the resulting matrix
	}
	return total;
}

#endif
