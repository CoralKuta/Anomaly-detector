/*
 * anomaly_detection_util.h
 *
 * Author: Noa Eitan 316222777, Coral Kuta 208649186
 */

#ifndef ANOMALYDETECTORUTIL_H_
#define ANOMALYDETECTORUTIL_H_

// return the average of the values that in the array
float avg(float* x, int size);

// returns the variance of X
float var(float* x, int size);

// returns the covariance of X and Y
float cov(float* x,  float* y, int size);


// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size);

class Line{
public:
	float a,b;
	Line():a(0),b(0){}
	Line(float a, float b):a(a),b(b){}

    // return f(x) from the liner equation of the line
	float f(float x){
		return a*x+b;
	}
};

class Point{
public:
	float x,y;

	Point(float x, float y):x(x),y(y){}

    Point():x(0), y(0){}
};

// performs a linear regression and returns the line equation
Line linear_reg(Point** points, int size);

// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size);

// returns the deviation between point p and the line
float dev(Point p,Line l);

#endif
