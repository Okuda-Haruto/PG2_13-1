#pragma once

class Enemy {
private:
	float PosX_;
	float PosY_;
	float VelocityX_ = 8.0f;
	float radius_ = 16.0f;
public:
	static int isAlive_;
	Enemy(int number);
	void Move();
	void Contact(float X,float Y,float radius);
	void Draw();
};