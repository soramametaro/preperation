#define GL_SILENCE_DEPRECATION

// #include <GL/gl.h>
#include <OpenGL/OpenGL.h>
// #include <GL/glut.h>
#include <GLUT/glut.h>
#include <cmath>
#include <math.h>
#include <stdio.h>

// レンダリングの関数
void display(void) {
  // スクリーンと変換行列を初期化
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  // 課題は以下の部分を変更する

  // 1:黄色四角
  glBegin(GL_POLYGON);
  glColor3d(1.0, 1.0, 0.0);
  glVertex3f(0.8, 0.8, 0);
  glVertex3f(0.3, 0.8, 0);
  glVertex3f(0.3, 0.3, 0);
  glVertex3f(0.8, 0.3, 0);
  glEnd();

  // 2:黒枠四角
  glBegin(GL_LINE_LOOP);
  glColor3d(0, 0, 0);
  glVertex3f(-0.3, 0.8, 0);
  glVertex3f(-0.8, 0.8, 0);
  glVertex3f(-0.8, 0.3, 0);
  glVertex3f(-0.3, 0.3, 0);
  glEnd();

  // 3:青星
  glColor3f(0.0, 0.0, 1.0); // 青色
  for (int i = 0; i < 5; i++) {
    glPushMatrix();
    glRotatef(72 * i, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0.6, 0);
    glVertex3f(-0.15, 0.15, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0.15, 0.15, 0);
    glEnd();
    glPopMatrix();
  }

  // 4:ピンクコ
  glColor3d(1, 0, 1);
  glBegin(GL_POLYGON);
  glVertex3f(-0.4, -0.2, 0);
  glVertex3f(-0.8, -0.2, 0);
  glVertex3f(-0.8, -0.8, 0);
  glVertex3f(-0.4, -0.8, 0);
  glEnd();

  // 中を白で埋める
  glColor3d(1, 1, 1);
  glBegin(GL_POLYGON);
  glVertex3f(-0.6, -0.4, 0);
  glVertex3f(-0.8, -0.4, 0);
  glVertex3f(-0.8, -0.6, 0);
  glVertex3f(-0.6, -0.6, 0);
  glEnd();

  // 5:多角形
  glColor3d(0, 1, 1);
  glTranslatef(0, -0.7, 0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 10; i++) {
    double angle = 2.0 * M_PI * i / 10;
    double x = 0.2 * cos(angle);
    double y = 0.2 * sin(angle);
    glVertex3f(x, y, 0);
  }
  glEnd();

  glFlush(); // スクリーンへ表示
}

// ウィンドウの大きさが変わった時に呼ばれる関数
void myReshape(int w, int h) {
  glViewport(0, 0, w, h); // スクリーンの大きさを決める

  // 変換行列を設定
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // 平行投影のためのパラメータを設定
  // 見える領域は (-1,-1,-1) と (1,1,1) をコーナーに持つ立方体の中
  glOrtho(-1, 1, // 左右
          -1, 1, // 下上
          -1, 1  // 手前奥
  );

  glMatrixMode(GL_MODELVIEW); // 図形描画モードへ切り替え
}

void myinit() {
  // 背景の色を設定 (４番目は透過度で通常は不透明なので 1 を設定)
  glClearColor(1, 1, 1, 1);
}

int main(int argc, char **argv) {
  // ウィンドウの初期化
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 使用するバッファの設定
  glutInitWindowSize(500, 500);                // ウィンドウの大きさ
  glutCreateWindow("1-1");                     // ウィンドウのタイトル

  myinit(); // OpenGL の初期化
  glutReshapeFunc(
      myReshape); // ウィンドウサイズが変更された時に呼ばれる関数を設定
  glutDisplayFunc(display); // ウィンドウの更新のための関数を設定
  glutMainLoop();           // メインループ

  return 0;
}
