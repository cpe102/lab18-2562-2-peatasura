#include<iostream>
#include<cmath>

using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect R1;
	Rect R2;

	cout << "Please input Rect 1 (x y w h): ";
	cin >> R1.x >> R1.y >> R1.w >> R1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> R2.x >> R2.y >> R2.w >> R2.h;
	
    double over = overlap(&R1,&R2) > 0 ? overlap(&R1,&R2) : 0 ;
	cout << "Overlap area = " <<  over ;	
	return 0;
}

double overlap(Rect *R1,Rect *R2)
{
	double ver,hon;
	double r1_x=R1->x+R1->w;
	double r2_x=R2->x+R2->w;
	hon =  min(r1_x,r2_x) - max(R1->x,R2->x);
	double r1_y = R2->y - R1->h;
	double r2_y = R2->y - R2->h;
	ver =  min(R1->y,R2->y) - max(r1_y,r2_y);
    
    // return hon*ver > 0 ? hon*ver : 0 ;
    return hon*ver ;
}