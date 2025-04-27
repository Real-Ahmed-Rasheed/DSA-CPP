#include<iostream>
using namespace std;
int main(){
    //jaggered array
    int rows;
    cin>>rows;
    int col;
    //number of columns for each row
    int* cols = new int[rows];
    //array of pointers of size (row)
    int** arr = new int*[rows];
    for(int i=0; i<rows; i++){
        cout<<"Enter Column Size";
        cin>>col;
        //create an array of size col and point the pointer to it
        arr[i] = new int[col];
    //to store number of columns for each row
        cols[i] = col;
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols[i]; j++){
            cout<<"Enter Value ";
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols[i]; j++){
            cout<<arr[i][j]<<" ";
        } cout<<endl;
    }
    
    return 0;
}