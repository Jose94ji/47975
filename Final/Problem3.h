#ifndef PROBLEM3_H
#define PROBLEM3_H


template<class T>

class Prob3Table

{

protected:

int rows; //Number of rows in the table

int cols; //Number of cols in the table

T *rowSum; //RowSum array

T *colSum; //ColSum array

T *table; //Table array

T grandTotal; //Grand total

void calcTable(void); //Calculate all the sums

public:

Prob3Table(char *,int,int); //Constructor then Destructor

~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};

const T *getTable(void){return table;};

const T *getRowSum(void){return rowSum;};

const T *getColSum(void){return colSum;};

T getGrandTotal(void){return grandTotal;};

};


template<class T>

//Opens the file and rows and cols
Prob3Table<T>::Prob3Table(char *fname,int rs,int cs)

{

rowSum = new T[rs];

colSum = new T[cs];

table = new T[rs * cs];

rows = rs;

cols = cs;

ifstream infile(fname);

for (int i = 0; i < rs; i++)

for (int j = 0; j < cs; j++)

infile >> table[i*cs+j];
//Closes the file
infile.close();

}


template<class T>

//Calculates the sum of the rowa
void Prob3Table<T>::calcTable(void)

{

int i, j;

grandTotal = 0;

for (i = 0; i < rows; i++)

{

rowSum[i] = 0;

for (j = 0; j < cols; j++)

rowSum[i] += table[i*cols+j];

grandTotal += rowSum[i];

}

for (i = 0; i < cols; i++)

{

colSum[i] = 0;

for (j = 0; j < rows; j++)

colSum[i] += table[j*cols+i];

}

}



template<class T>
//New table
class Prob3TableInherited:public Prob3Table<T>

{

protected:

T *augTable; //Augmented Table with sums

public:

Prob3TableInherited(char *,int,int); //Constructor

~Prob3TableInherited(){delete [] augTable;}; //Destructor

const T *getAugTable(void){return augTable;};

};


template<class T>

Prob3TableInherited<T>::Prob3TableInherited(char *fname,int rs,int cs)

: Prob3Table<T>(fname, rs, cs)

{

int i, j;

calcTable();

augTable = new int[(rs+1)*(cs+1)];

for (i = 0; i < rs; i++)

{

for (j = 0; j < cs; j++)

augTable[i*(cs+1)+j] = table[i*cs+j];

}

for (i = 0; i < rs; i++)

augTable[i*(cs+1)+cs] = rowSum[i];

for (i = 0; i < cs; i++)

augTable[rs*(cs+1)+i] = colSum[i];

augTable[rs*(cs+1)+cs] = grandTotal;}

#endif