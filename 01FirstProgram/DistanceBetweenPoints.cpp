#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

class Point{
    int x ,y ;
    friend float distance_BW_Points(Point , Point);
    public:
    Point (int a ,int b){
        x=a;
        y=b;
    }
    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

float distance_BW_Points(Point p1, Point p2){
   return sqrt( pow( (p2.x - p1.x) ,2) + pow( (p2.y - p1.y) , 2) );
};

int main(int argc, char const *argv[])
{
    Point p1 = Point(1,6);
    p1.display();
    Point p2 = Point(4,3);
    p2.display();
    float distance = distance_BW_Points(p1, p2);
    cout<<"The distance is : "<< setprecision(3) <<distance<<endl;
    return 0;
}
