/*
 * anomaly_detection_util.cpp
 *
 * Author: Noa Eitan 316222777, Coral Kuta 208649186
 */

#include <cmath>
#include "anomaly_detection_util.h"

// return the average of the values that in the array
float avg(float* x, int size){
    float sum = 0;

    // sum the values from the array
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }

    // return the average
    return (sum / (float) size);
}

// returns the variance of X
float var(float* x, int size){
    float squared_sum = 0;

    // summing the squared values that in the x array
    for (int i = 0; i < size; i++) {
        squared_sum += (x[i] * x[i]);
    }

    //calculate the average of the original x array
    float average = avg(x, size);

    //return the variance according to the equation
    return  (((squared_sum / (float) size)) - (average * average));
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    float sum_multiplied_xy = 0;

    // summing the multiplied of x and y values that in the arrays
    for (int i = 0; i < size; i++) {
        sum_multiplied_xy += (x[i] * y[i]);
    }

    //return the covariance according to the equation
    return ((sum_multiplied_xy / (float) size) - (avg(x, size) * avg(y, size)));
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size) {
    // calculate the pearson according to the equation
	return (cov(x, y, size)) / (sqrtf(var(x, size)) * sqrtf(var(y, size)));
}

// performs a linear regression and returns the line equation
Line linear_reg(Point** points, int size){
    float a, b;

    // initial arrays of x and y values of the points
    float *x = new float [size];
    float *y = new float [size];

    // going through the points array and creating x values array and y values array
    for (int i = 0; i < size; i++) {
        x[i] = points[i]->x;
        y[i] = points[i]->y;
    }

    // calculate a
    a = (cov(x, y, size) / var(x, size));

    // calculate b
    b = (avg(y, size) - (a * avg(x, size)));

    // deleting the new objects
    delete[] x;
    delete[] y;

	return {a, b};
}

// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
    // return the deviation between point p and the line
    return dev(p, linear_reg(points, size));
}

// returns the deviation between point p and the line
float dev(Point p,Line l){
    // save the y value of the point
    float y = p.y;

    // get the real value of y (f(x))
    float fx = l.f(p.x);

    // return the absolute distance between the y value of the point and the y value of the line
    if (y >= fx) {
        return (y - fx);
    } else {
        return (fx - y);
    }
}






