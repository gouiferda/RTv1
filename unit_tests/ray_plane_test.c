#include<stdio.h>
 
typedef struct{
	double x,y,z;
}vector;
 
vector addVectors(vector a,vector b){
	return (vector){a.x+b.x,a.y+b.y,a.z+b.z};
}
 
vector subVectors(vector a,vector b){
	return (vector){a.x-b.x,a.y-b.y,a.z-b.z};
}
 
double dotProduct(vector a,vector b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
 
vector scaleVector(double l,vector a){
	return (vector){l*a.x,l*a.y,l*a.z};
}
 
vector intersectionPoint(vector lineVector, vector linePoint, vector planeNormal, vector planePoint){
	vector diff = subVectors(linePoint,planePoint);
 
	return addVectors(addVectors(diff,planePoint),scaleVector(-dotProduct(diff,planeNormal)/dotProduct(lineVector,planeNormal),lineVector));
}
 
int main()
{

	vector lV = {0,0,0}; //line direction
    vector lP = {0,2,0}; //point on line
    vector pN = {0,0,2}; //normal to plane
    vector pP = {0,0,0}; // point on plane
    vector iP;


		if(dotProduct(lV,pN)==0)
			printf("Line and Plane do not intersect, either parallel or line is on the plane");
		else{
 
			iP = intersectionPoint(lV,lP,pN,pP);
 
			printf("Intersection point is (%lf,%lf,%lf)",iP.x,iP.y,iP.z);
		}
	
 
	return 0;
}