#include <stdio.h>
#include <math.h>
#include <GL/glut.H>

//レンダリングの関数
void display(void){ 
  //スクリーンと変換行列を初期化
  glClear(GL_COLOR_BUFFER_BIT); 
  glLoadIdentity();
  
  //電荷の x 座標
  float a[5] = {0, 0.5, -0.5, -0.5, 0.5};
  //電荷の y 座標
  float b[5] = {0, 0.5, 0.5, -0.5, -0.5};
  //電荷の値
  float q[5] = {0.125, 0.25, -0.25, 0.25, -0.25};
  
  //課題は以下の部分を追加する
  
  //※ 2番を先に描く (1番を上書きしないように)
  //2重 for で色を変えながら小さな正方形を敷き詰める
  int N = 500; //正方形の数
  
  
  //※ 1番を後に描く
  //円周の座標には配列を使いましょう (長さは十分大きめにしてます)
  float x[100]; //原点が中心で半径が 0.1 の円の x 座標 
  float y[100]; //原点が中心で半径が 0.1 の円の y 座標
  
  int M  = 20; //20角形ぐらいにしましょうか
  float r = 0.1; //円の半径
  //配列 x,y に円の座標を for 文で代入
  
  
  //代入したら円を書いていく (中心の座標を足して円の中心をずらす)
  
  
  
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
  glClearColor (0.5, 0.5, 0.5, 1);

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

