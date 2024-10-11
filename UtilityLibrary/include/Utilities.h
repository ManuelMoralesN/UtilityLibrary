#pragma once


inline 
float 
sqrt(float value) {
	if (value < 0) {
		return 0;
	}

	float x = value;
	float y = 1.0f;
	float epsilon = 0.00001f;
	while (x - y > epsilon) {
		x = (x + y) / 2.0f;
		y = value / x;
	}
	return x;
}
