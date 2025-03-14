#include <stdio.h>
#include <math.h>
#include <GL/glut.H>

//レンダリングの関数
void display(void){ 
  //スクリーンと変換行列を初期化
  glClear(GL_COLOR_BUFFER_BIT); 
  glLoadIdentity();
  
  //課題は以下の部分を変更する
  glPointSize(10); //点の大きさの設定 10 画素分
  glBegin(GL_POINTS);
    glColor3f(1,0,0); //赤
    glVertex3f(0,0.5,0);
    glColor3f(0,1,0); //緑
    glVertex3f(0,0,0);
    glColor3f(0,0,1); //青
    glVertex3f(0.5,0,0);
  glEnd();
  
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

