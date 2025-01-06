#include <Enemy.h>
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

int Enemy::isAlive_ = TRUE;

Enemy::Enemy(int number) {
	PosX_ = number * 300.0f + 200.0f;
	PosY_ = number * 200.0f + 200.0f;
}

void Enemy::Move() {
	PosX_ += VelocityX_;

	if (PosX_ + radius_ > 1280) {
		PosX_ = 1280 - radius_;
		VelocityX_ = -VelocityX_;
	} else if (PosX_ - radius_ < 0) {
		PosX_ = 0 + radius_;
		VelocityX_ = -VelocityX_;
	}
}

void Enemy::Contact(float X,float Y,float radius) {
	if (radius_ + radius > sqrtf(powf(PosX_ - X, 2) + powf(PosY_ - Y, 2))) {
		isAlive_ = FALSE;
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(int(PosX_), int(720 - PosY_), int(radius_), int(radius_), 0.0f, 0xFF0000FF, kFillModeSolid);
	}
}