#include <Bullet.h>
#include <Novice.h>

void Bullet::isShot(float X,float Y) {
	PosX_ = X;
	PosY_ = Y;
	isAlive_ = TRUE;
}

void Bullet::Move() {
	PosY_ += VelocityY_;

	if (PosY_ - radius_ > 720) {
		isAlive_ = FALSE;
	}
}

void Bullet::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(int(PosX_), int(720 - PosY_), int(radius_), int(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}