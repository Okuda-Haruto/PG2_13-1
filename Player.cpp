#include <Player.h>
#include <Novice.h>

Player::Player() {
	PosX_ = 640;
	PosY_ = 80;
}

float Player::X() {
	return PosX_;
}

float Player::Y() {
	return PosY_;
}

void Player::Move(char *keys) {
	VelocityX_ = 0;
	VelocityY_ = 0;

	if (keys[DIK_W]) {
		VelocityY_ += 8.0f;
	}
	if (keys[DIK_S]) {
		VelocityY_ -= 8.0f;
	}
	if (keys[DIK_D]) {
		VelocityX_ += 8.0f;
	}
	if (keys[DIK_A]) {
		VelocityX_ -= 8.0f;
	}

	PosX_ += VelocityX_;
	PosY_ += VelocityY_;

	if (PosX_ + radius_ > 1280) {
		PosX_ = 1280 - radius_;
	} else if (PosX_ - radius_ < 0) {
		PosX_ = 0 + radius_;
	}
	if (PosY_ + radius_ > 720) {
		PosY_ = 720 - radius_;
	} else if (PosY_ - radius_ < 0) {
		PosY_ = 0 + radius_;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(int(PosX_), int(720 - PosY_), int(radius_), int(radius_), 0.0f, 0x00FF00FF, kFillModeSolid);
}