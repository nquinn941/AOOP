#include "shape.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>


Shape::Shape(){
}

Shape::~Shape(){
	std::cout << "Destructor - Shape" <<std::endl;
}

Circle::Circle(float x,float y,float r):x(x),y(y),r(r){	
}

Circle::~Circle(){
	std::cout << "Destructor - Circle" <<std::endl;
}

std::string Circle::to_string() const{
	std::stringstream sstr;
	sstr << "Circle centred at " << "(" << x << "," << y << ")" << " with a radius " << r;
	std::string str = sstr.str();
	return str;
}

void Circle::centre_at(float new_x, float new_y){
	x=new_x;
	y=new_y;
}

Rectangle::Rectangle(float x0, float y0,float x1, float y1):x0(x0),y0(y0),x1(x1),y1(y1){
}

Rectangle::~Rectangle(){
	std::cout << "Destructor - Rectangle" <<std::endl;
}

std::string Rectangle::to_string() const{
	std::stringstream sstr;
	sstr << "Rectangle at " << "[(" << x0 << "," << y0 << "), (" << x1 << "," << y1 << ")] with width " << x1-x0 << " and height " << y1-y0;
	std::string str = sstr.str();
	return str;
}

void Rectangle::centre_at(float x, float y){
	float width = x1 - x0;
	float height = y1 - y0;

	x0 = x-(width/2);
	x1 = x+(width/2);

	y0 = y-(height/2);
	y1 = y+(height/2);

}

Triangle::Triangle(float x0, float y0,float x1, float y1,float x2, float y2):x0(x0),y0(y0),x1(x1),y1(y1),x2(x2),y2(y2){
}

Triangle::~Triangle(){
	std::cout << "Destructor - Triangle" <<std::endl;
}


std::string Triangle::to_string() const{

	float ab,bc,ac;
	if((y1-y0)==0){
		ab = x1 -x0;
	}
	else if((x1-x0)==0){
		ab = y1 -y0;
	}
	else{
		ab = ((y1-y0)/(x1-x0));
	}

	if((y2-y1)==0){
		bc = x2 -x1;
	}
	else if((x2 -x1)==0){
		bc = y2-y1;
	}
	else{
		bc = ((y2-y1)/(x2-x1));
	}

	float abbc = pow(ab,2) + pow (bc,2);
	ac = sqrt(abbc);

	
	std::stringstream sstr;
	sstr << "Triangle at " << "[(" << x0 << "," << y0 << "), (" << x1 << "," << y1 << "), (" <<x2 << "," <<y2 <<")] with side lengths " <<ab << "," <<bc << "," <<ac;
	std::string str = sstr.str();
	return str;
}

void Triangle::centre_at(float x, float y){
	float current_centriod_x = (x0+x1+x2)/3;
	float current_centriod_y = (y0+y1+y2)/3;

	float x0_diff = x0 - current_centriod_x;
	float x1_diff = x1 - current_centriod_x;
	float x2_diff = x2 - current_centriod_x;

	float y0_diff = y0 - current_centriod_y;
	float y1_diff = y1 - current_centriod_y;
	float y2_diff = y2 - current_centriod_y;

	x0 = x0_diff + x;
	x1 = x1_diff + x;
	x2 = x2_diff + x;

	y0 = y0_diff + y;
	y1 = y1_diff + y;
	y2 = y2_diff + y;
}

