#pragma once

#ifdef GELCORE_EXPORT
#define GELCORE_API __declspec(dllexport)
#else
#define GELCORE_API __declspec(dllimport)
#endif

#include "Matrix4.h"

namespace GelCore
{
	class Vector4
	{
	public:
		Vector4(void);
		Vector4(const Vector4* v);
		Vector4(double* inputArray);

		//inline double operator[] (int i) { return entries[i]; }
		inline double& operator[] (int i) { return entries[i]; }
		Vector4& operator+=(const Vector4& v) {
			for (int i = 0; i < 4; ++i) {
				entries[i] += v.Get(i);
			}
			return *this;
		}
		Vector4& operator*=(const Vector4& v) {
			for (int i = 0; i < 4; ++i) {
				entries[i] *= v.Get(i);
			}
			return *this;
		}
		const Vector4 operator+(const Vector4& v) const {
			Vector4 result(*this);
			result += v;
			return result;
		}
		const Vector4 operator*(const Vector4& v) const {
			Vector4 result(*this);
			result *= v;
			return result;
		}
		inline double Get(unsigned i) const { return entries[i]; }
		inline void Set(unsigned i, double d) { entries[i] = d; }
		void Clear();
		void Normalize();
		double DotProduct(Vector4* v);
		void Multiply(GelCore::Matrix4* m, Vector4* result);
		void ToArray(double* ary);
	private:
		double entries[4];
	};
}