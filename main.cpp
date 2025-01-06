#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

const char kWindowTitle[] = "LC1A_02_オクダハルト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player *player = new Player;

	Bullet* bullet[8];
	for (int i = 0; i < 8; i++) {
		bullet[i] = new Bullet();
	}

	Enemy *enemyA = new Enemy(0);
	Enemy *enemyB = new Enemy(1);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Move(keys);

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			for (int i = 0; i < 8; i++) {
				if (!bullet[i]->isAlive()) {
					bullet[i]->isShot(player->X(), player->Y());
					break;
				}
			}
		}

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive_ = TRUE;
		}

		for (int i = 0; i < 8; i++) {
			if (bullet[i]->isAlive()) {
				bullet[i]->Move();
			}
		}

		if (Enemy::isAlive_) {
			enemyA->Move();
			enemyB->Move();
		}

		for (int i = 0; i < 8; i++) {
			if (bullet[i]->isAlive()) {
				enemyA->Contact(bullet[i]->X(), bullet[i]->Y(), bullet[i]->radius());
				enemyB->Contact(bullet[i]->X(), bullet[i]->Y(), bullet[i]->radius());
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		for (int i = 0; i < 8; i++) {
			if (bullet[i]->isAlive()) {
				bullet[i]->Draw();
			}
		}

		if (Enemy::isAlive_) {
			enemyA->Draw();
			enemyB->Draw();
		}

		Novice::ScreenPrintf(0, 0,"enemyA isAlive = %d", Enemy::isAlive_);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", Enemy::isAlive_);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
