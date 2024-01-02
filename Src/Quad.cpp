#include "Quad.hpp"

void Quad::SetX(float x) {
	mX = x;
}
float Quad::GetX() const {
	return mX;
}
void Quad::SetY(float y) {
	mY = y;
}
float Quad::GetY() const {
	return mY;
}
void Quad::Position(float x, float y) {
	SetX(x);
	SetY(y);
}
void Quad::SetWidth(float w) {
	mWidth = w;
}
float Quad::GetWidth() const {
	return mWidth;
}
void Quad::SetHeight(float h) {
	mHeight = h;
}
float Quad::GetHeight() const {
	return mHeight;
}
void Quad::Size(float w, float h) {
	SetWidth(w);
	SetHeight(h);
}
void Quad::Draw() {
	// Get the top-left and bottom-right of quad
	float origX = mX - (mWidth * 0.5);
	float origY = mY - (mHeight * 0.5);
	float destX = origX + mWidth;
	float destY = origY + mHeight;
	// 0.0 : SIZE -> 0.0 : 1.0
	origX /= Settings::Width;
	origY /= Settings::Height;
	destX /= Settings::Width;
	destY /= Settings::Height;
	// 0.0 : 1.0 -> -0.5 : 0.5
	origX -= 0.5;
	origY -= 0.5;
	destX -= 0.5;
	destY -= 0.5;
	// -0.5 : 0.5 -> -1.0 : 1.0
	origX *= 2.0;
	origY *= 2.0;
	destX *= 2.0;
	destY *= 2.0;
	// now we flip the y
	origY *= -1.0;
	destY *= -1.0;
	// draw
	glBegin(GL_TRIANGLES);
	glVertex2f(origX, origY);
	glVertex2f(destX, origY);
	glVertex2f(origX, destY);
	glVertex2f(destX, origY);
	glVertex2f(origX, destY);
	glVertex2f(destX, destY);
	glEnd();
}
