#include<iostream>
using namespace std;

class maxHeap{
    int* arr;
    int currSize;
    int maxSize;
    public:
        maxHeap(int size){
            this->maxSize = size;
            arr= new int[maxSize];
            currSize = 0;
        }
        void insert(int num){
            if (currSize == maxSize) {
                cout << "Heap is full. Cannot insert more elements." << endl;
                return;
            }
    
            int i = currSize;
            arr[i] = num;
            currSize++;
            //step-up propogation
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (arr[parent] < arr[i]) {
                    swap(arr[parent], arr[i]);
                    i = parent;
                } else {
                    break;
                }
            }
            
        }
        void destroy(){
            //will always destroy root node
            arr[0] = arr[currSize];
            currSize--;
            heapify(0);
        }
        void heapify(int index){
            //step down propogation
            int left = 2*index+1;
            int right = 2*index+2;
            int largest = index;
            if(left < maxSize && arr[left] > arr[index]){
                largest = left;
            }
            if(right < maxSize && arr[right] > arr[index]){
                largest = right;
            }
            swap(arr[largest], arr[index]);
            if(largest != index){
                //means there was larger on left or right as 
                //largest has been changed
                heapify(largest);
            }
        }
        void print(){
            for (int i = 0; i < currSize; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            
        }
};
int main(){
    maxHeap h = maxHeap(10);
    h.insert(30);
    h.insert(20);
    h.insert(50);
    h.insert(40);
    h.insert(500);
    h.insert(60);
    h.print();
    h.destroy();
    h.print();
    return 0;
}