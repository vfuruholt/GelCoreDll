#pragma once

#ifdef GELCORE_EXPORT
#define GELCORE_API __declspec(dllexport)
#else
#define GELCORE_API __declspec(dllimport)
#endif

namespace GelCore
{
	// Fastest dimension is columns
	class Matrix4
	{
	public:
		Matrix4(void);
		Matrix4(double* values);

		void Identity();
		//inline double Get(unsigned i) { return entries[i]; }
		inline double Get(unsigned i, unsigned j) { return entries[i][j]; }
		//inline void Set(unsigned i, double d) { entries[i] = d; }
		inline void Set(unsigned i, unsigned j, double d) { entries[i][j] = d; }
		inline void Set(Matrix4* m) {
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					entries[i][j] = m->Get(i, j);
				}
			}
		}
		inline void Set(double* vals) {
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					entries[i][j] = vals[i * 4 + j];
				}
			}
		}
		void Multiply(Matrix4* m);
		void Multiply(const double d);
		//static Matrix4* Multiply(Matrix4* m1, Matrix4* m2):

		void ToArray(double* ary);

		inline int NumRows() { return 4; }
		inline int NumCols() { return 4; }
	private:
		double entries[4][4];
	};
}
