

#include "headers.h"
 
t_vector intersectionPoint(t_vector lineVector, t_vector linePoint, t_vector planeNormal, t_vector planePoint){
	t_vector diff = vectSub(linePoint,planePoint);
 
	return vectAdd(vectAdd(diff,planePoint),
	vectScale(lineVector, -vectDot(diff,planeNormal)/vectDot(lineVector,planeNormal)));
}
 
int main()
{

	t_vector lV = {0,0,0}; //line direction
    t_vector lP = {0,2,0}; //point on line
    t_vector pN = {0,0,2}; //normal to plane
    t_vector pP = {0,0,0}; // point on plane
    t_vector iP;


		if(vectDot(lV,pN)==0)
			printf("Line and Plane do not intersect, either parallel or line is on the plane");
		else{

			iP = intersectionPoint(lV,lP,pN,pP);
 
			printf("Intersection point is (%lf,%lf,%lf)",iP.x,iP.y,iP.z);
		}
	
 
	return 0;
}