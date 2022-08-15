#pragma once
struct Vector3
{
	float x;
	float y;
	float z;
	Vector3() {};
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};
	Vector3 operator+(Vector3 Other) {
		return Vector3{ x + Other.x, y + Other.y, z + Other.z };
	}
	Vector3 operator-(Vector3 Other) {
		return Vector3{ x - Other.x, y - Other.y, z - Other.z };
	}
	Vector3 operator*(float f) {
		return Vector3{ x * f, y * f, z * f };
	}
};

