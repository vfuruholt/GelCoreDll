#pragma once

#ifdef GELCORE_EXPORTS
#define GELCORE_API __declspec(dllexport)
#else
#define GELCORE_API __declspec(dllimport)
#endif

#include <string>
#include <windows.h>
#include <GL/gl.h>
#include "Vector4.h"
#include "Utilities.h"

namespace GelCore
{
	// Span3D is a box defined by a corner point (origin) and three vectors.
	// For bounding boxes, the three vectors should be orthogonal and spanning the 
	// local coordinate space for an object.
	// TODO: Define this struct according to text definition above.
	struct Span3D
	{
		Vertex3 VtxMin;
		Vertex3 VtxMax;
		//Vertex3 origin;
		//std::vector<Vertex3*> spanVectors; 
	};

	class Drawable
	{
	public:
		GELCORE_API Drawable(void);

		GELCORE_API virtual bool Load() { return false; };
		virtual void DrawPoints() {};
		virtual void DrawLines() {};
		virtual void DrawFilled() {};

		Span3D bbox;
		std::string name;
	protected:
		std::string filename;

		virtual void CalcBoundingBox() = 0;
		void InterpolateColor(GLdouble* startColor, GLdouble* endColor, GLdouble* intpColor, double relPos);
	};
}
