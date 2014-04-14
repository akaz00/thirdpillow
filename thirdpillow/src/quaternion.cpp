/*
 * quaternion.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "quaternion.h"

quaternion::quaternion() {
	// TODO Auto-generated constructor stub

}

quaternion::quaternion(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

quaternion::~quaternion() {
	// TODO Auto-generated destructor stub
}

void quaternion::set_x(float x) {
	this->x = x;
}

void quaternion::set_y(float y) {
	this->y = y;
}

void quaternion::set_z(float z) {
	this->z = z;
}

void quaternion::set_w(float w) {
	this->w = w;
}

float quaternion::get_x() {
	return this->x;
}

float quaternion::get_y() {
	return this->y;
}

float quaternion::get_z() {
	return this->z;
}

float quaternion::get_w() {
	return this->w;
}

float quaternion::magnitude() {
	return (float) sqrt(
			this->x * this->x + this->y * this->y + this->z * this->z
					+ this->w * this->w);
}

void quaternion::normalize() {
	float magnitude = this->magnitude();
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
	this->w /= magnitude;
}

void quaternion::conjugate() {
	float x_prime = -this->x;
	float y_prime = -this->y;
	float z_prime = -this->z;
	float w_prime = this->w;
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
	this->w = w_prime;
}

void quaternion::multiply(quaternion* q) {
	float w_prime = w * q->get_w() - x * q->get_x() - y * q->get_y()
			- z * q->get_z();
	float x_prime = x * q->get_w() + w * q->get_x() + y * q->get_z()
			- z * q->get_y();
	float y_prime = z * q->get_w() + w * q->get_y() + z * q->get_x()
			- x * q->get_z();
	float z_prime = y * q->get_w() + w * q->get_z() + x * q->get_y()
			- y * q->get_x();
	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
	this->w = w_prime;
}

void quaternion::multiply(vector3* v) {
	float x_prime = w * v->get_x() + y * v->get_z() - z * v->get_y();
	float y_prime = w * v->get_y() + z * v->get_x() - x * v->get_z();
	float z_prime = w * v->get_z() + x * v->get_y() - y * v->get_x();
	float w_prime = -x * v->get_x() - y * v->get_y() - z * v->get_z();

	this->x = x_prime;
	this->y = y_prime;
	this->z = z_prime;
	this->w = w_prime;
}

quaternion* quaternion::clone() {
	quaternion* clone = new quaternion(this->x, this->y, this->z, this->w);

}