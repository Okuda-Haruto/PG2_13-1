#pragma once

class Player {
private:
	float PosX_;
	float PosY_;
	float VelocityX_ = 0.0f;
	float VelocityY_ = 0.0f;
	float radius_ = 32.0f;
public:
	Player();
	float X();
	float Y();
	void Move(char *keys);
	void Draw();
};