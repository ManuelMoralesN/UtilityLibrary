#pragma once
#include "Utilities.h"

class Vector2
{
public:
	float x;
	float y;

	Vector2() : x(0), y(0) {};

	Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

	~Vector2() = default;

	Vector2
		operator+(const Vector2& other) const {
		float new_xVal = x + other.x;
		float new_yVal = y + other.y;
		return Vector2(new_xVal, new_yVal);
	}

	Vector2
		operator-(const Vector2& other) const {
		float new_xVal = x - other.x;
		float new_yVal = y - other.y;
		return Vector2(new_xVal, new_yVal);
	}

	Vector2 
		operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	float 
		magnitude() const {
		return sqrt(x * x + y * y);
	}

	Vector2
		normalize() const {
		float mag = magnitude();
		if (mag == 0) {
			return Vector2(0, 0);
		}
		return Vector2(x / mag, y / mag);
	}

	float*
		data() {
		return &x;
	}

	const float*
		data() const {
		return &x;
	}

private:
};