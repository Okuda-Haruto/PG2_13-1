#pragma once

class Bullet {
private:
	int isAlive_ = false;
	float PosX_;
	float PosY_;
	float VelocityY_ = 8.0f;
	float radius_ = 16.0f;
public:
	int isAlive() { return isAlive_; };
	float X() { return PosX_; };
	float Y() { return PosY_; };
	float radius() { return radius_; };
	void isShot(float X, float Y);
	void Move();
	void Draw();
};