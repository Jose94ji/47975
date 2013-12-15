#ifndef PROBLEM2_H
#define PROBLEM2_H


//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
private:
int *index; //Index that is utilized in the sort
public:
Prob2Sort(){index=NULL;}; //Constructor
~Prob2Sort(){delete []index;}; //Destructor
T * sortArray(const T*,int,bool); //Sorts a single column array
T * sortArray(const T*,int,int,int,bool); //Sorts a 2 dimensional array
};


template<class T>
T* Prob2Sort<T>::sortArray(const  T* arry, int rows, int cols, int column, bool order)
{
    // put into new array to sort and return
    T* a_ray = new T[(rows*cols) + 1];

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
               a_ray[i*cols+j] = arry[i*cols+j];
        }
        cout << endl;
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
               cout << a_ray[i*cols+j] ; 
        }
        cout << endl;
    }

    T temp;
    bool test = true;

    do
    {
        test = false;
        for(int i = 0; i < rows - 1; i++)
        {
            cout << "Row " << i << endl;
            if(a_ray[i*cols+column] > a_ray[(i+1)*cols+column])
            {
                cout << "ELEMENT 1 IS " << a_ray[i*cols+column] << endl;
                temp = arry[i*cols+column];
                cout << "TEMP IS " << temp << endl;
                a_ray[i*cols+column] = a_ray[(i+1)*cols+column];
                cout << "ELEMENT 1 NEW is  " << a_ray[(i)*cols+column] << endl;
                cout << "ELEMENT 2 is " << a_ray[(i+1)*cols+column] << endl;
                a_ray[(i+1)*cols+column] = temp;
                cout << "ELEMENT 2 NEW is  " << a_ray[(i+1)*cols+column] << endl;
                test = true;
             } 

        }      
    }while(test);

	return  a_ray;
}


	



#endif