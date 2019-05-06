#pragma once

#ifdef GELCORE_EXPORT
#define GELCORE_API __declspec(dllexport)
#else
#define GELCORE_API __declspec(dllimport)
#endif

#include <vector>
#include <math.h>

namespace GelCore
{
	enum AttributeType { MVO, PVO, NMVO, PDVO };

	struct Vertex3
	{
		double x;
		double y;
		double z;

		Vertex3() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}
		Vertex3(double glx, double gly, double glz) {
			Init(glx, gly, glz);
		}

		void Init(double glx, double gly, double glz) {
			x = glx;
			y = gly;
			z = glz;
		}

		Vertex3& operator=(const Vertex3& vtx) {
			x = vtx.x;
			y = vtx.y;
			z = vtx.z;
			return *this;
		}
		Vertex3& operator+=(const Vertex3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Vertex3& operator-=(const Vertex3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		Vertex3& operator*=(const double d) {
			x *= d;
			y *= d;
			z *= d;
			return *this;
		}
		const Vertex3 operator+(const Vertex3& v) const {
			Vertex3 result(*this);
			result += v;
			return result;
		}
		const Vertex3 operator-(const Vertex3& v) const {
			Vertex3 result(*this);
			result -= v;
			return result;
		}
		const Vertex3 operator*(const double d) const {
			Vertex3 result(*this);
			result *= d;
			return result;
		}

		double dotProduct(const Vertex3& v) {
			return (x * v.x + y * v.y + z * v.z);
		}

		double innerProduct() {
			return dotProduct(*this);
		}

		double euclidNorm() {
			return sqrt(innerProduct());
		}

		const Vertex3 crossProduct(const Vertex3 & v) const {
			Vertex3 result(*this);
			result.x = y * v.z - z * v.y;
			result.y = z * v.x - x * v.z;
			result.z = x * v.y - y * v.x;
		}
	};

	static double VtxToLineDist(const Vertex3& vtx, const Vertex3& lineStart, const Vertex3& lineEnd);
	static double VtxToLineDist2D(const Vertex3& vtx, const Vertex3& lineStart, const Vertex3& lineEnd);
}