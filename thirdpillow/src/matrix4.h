/*
 * matrix4.h
 *
 *  Created on: Apr 10, 2014
 *      Author: jwpilly
 */

#ifndef MATRIX4_H_
#define MATRIX4_H_

#include <stdlib.h>
#include <stdio.h>
#include "vector2.h"

class matrix4 {
public:
	float* get_data();
	float get_at(int x, int y);
	void set_at(int x, int y, float value);
	void initialize_identity();
	void multiply(matrix4* m);
	matrix4();
	matrix4(float* data);
	virtual ~matrix4();

	matrix4* clone();
private:
	float matrix[4][4];
};

#endif /* MATRIX4_H_ */