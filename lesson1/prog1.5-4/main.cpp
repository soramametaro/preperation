#include <stdio.h>
#include <math.h>
#include <GL/glut.H>

//レンダリングの関数
void display(void){ 
  //スクリーンと変換行列を初期化
  glClear(GL_COLOR_BUFFER_BIT); 
  glLoadIdentity();
  
  //軸を書く
  glLineWidth(2);
  glColor3f(0,0,0);
  glBegin(GL_LINES);
     glVertex3f(-1, 0, 0);
     glVertex3f(1, 0, 0);
     glVertex3f(0, -1, 0);
     glVertex3f(0, 1, 0);
  glEnd();
  
  // 配列を使った方が楽なの使ってみましょう
  float x[1000]; //配列を使う (大きさが不明なので適当に大きな長さをとる)
  float y[1000]; //配列を使う (大きさが不明なので適当に大きな長さをとる)
  int N = 500; //線分の数 (変えても良い)
  
  //課題は以下の部分を追加する
  
  //配列x と 配列y へ値を代入する for 文を以下に書く
  
  
  glLineWidth(5); //線は少し太くしましょうか
  //線分を描く for 文を以下に書く
  
  glFlush(); //スクリーンへ表示
} 

//ウィンドウの大きさが変わった時に呼ばれる関数
void myReshape(int w, int h){
  glViewport(0, 0, w, h); //スクリーンの大きさを決める
  
  //変換行列を設定
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  
  //平行投影のためのパラメータを設定
  //見える領域は (-1,-1,-1) と (1,1,1) をコーナーに持つ立方体の中
  glOrtho(-1, 1, //左右
          -1, 1, //下上
          -1, 1 //手前奥
          );
  
  glMatrixMode(GL_MODELVIEW); //図形描画モードへ切り替え
} 

void myinit(){
  //背景の色を設定 (４番目は透過度で通常は不透明なので 1 を設定)
  glClearColor (1, 1, 1, 1);

}

int main(int argc, char** argv){
  //ウィンドウの初期化
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //使用するバッファの設定
  glutInitWindowSize(500, 500); //ウィンドウの大きさ
  glutCreateWindow("1-1"); //ウィンドウのタイトル
  
  
  myinit();//OpenGL の初期化
  glutReshapeFunc(myReshape);//ウィンドウサイズが変更された時に呼ばれる関数を設定
  glutDisplayFunc(display); //ウィンドウの更新のための関数を設定
  glutMainLoop(); //メインループ
  
  return 0;
}

