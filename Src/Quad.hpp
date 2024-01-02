#ifndef QUAD_HPP
#define QUAD_HPP

#include <GLFW/glfw3.h>
#include "Settings.hpp"

class Quad {
private:
	float mX;
	float mY;
	float mWidth;
	float mHeight;
public:
	void SetX(float x);
	float GetX() const;
	void SetY(float y);
	float GetY() const;
	void Position(float x, float y);
	void SetWidth(float w);
	float GetWidth() const;
	void SetHeight(float h);
	float GetHeight() const;
	void Size(float w, float h);
	void Draw();
};

#endif
