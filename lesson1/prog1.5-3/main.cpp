#include <stdio.h>
#include <math.h>
#include <GL/glut.H>

//�����_�����O�̊֐�
void display(void){ 
  //�X�N���[���ƕϊ��s���������
  glClear(GL_COLOR_BUFFER_BIT); 
  glLoadIdentity();
  
  //�ۑ�͈ȉ��̕�����ύX����
  int N = 10;
  glLineWidth(5);
  for(int i=0; i<N; i++){
    if(i%2 == 0)
      glColor3f(0, 0, 1);
    else
      glColor3f(1, 0, 0);
    glBegin(GL_LINES);
      glVertex3f( (float)i/N, 0, 0);
      glVertex3f( (float)(i+1)/N, 0, 0);
    glEnd();
  }
  
  glFlush(); //�X�N���[���֕\��
} 

//�E�B���h�E�̑傫�����ς�������ɌĂ΂��֐�
void myReshape(int w, int h){
  glViewport(0, 0, w, h); //�X�N���[���̑傫�������߂�
  
  //�ϊ��s���ݒ�
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  
  //���s���e�̂��߂̃p�����[�^��ݒ�
  //������̈�� (-1,-1,-1) �� (1,1,1) ���R�[�i�[�Ɏ������̂̒�
  glOrtho(-1, 1, //���E
          -1, 1, //����
          -1, 1 //��O��
          );
  
  glMatrixMode(GL_MODELVIEW); //�}�`�`�惂�[�h�֐؂�ւ�
} 

void myinit(){
  //�w�i�̐F��ݒ� (�S�Ԗڂ͓��ߓx�Œʏ�͕s�����Ȃ̂� 1 ��ݒ�)
  glClearColor (1, 1, 1, 1);

}

int main(int argc, char** argv){
  //�E�B���h�E�̏�����
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //�g�p����o�b�t�@�̐ݒ�
  glutInitWindowSize(500, 500); //�E�B���h�E�̑傫��
  glutCreateWindow("1-1"); //�E�B���h�E�̃^�C�g��
  
  
  myinit();//OpenGL �̏�����
  glutReshapeFunc(myReshape);//�E�B���h�E�T�C�Y���ύX���ꂽ���ɌĂ΂��֐���ݒ�
  glutDisplayFunc(display); //�E�B���h�E�̍X�V�̂��߂̊֐���ݒ�
  glutMainLoop(); //���C�����[�v
  
  return 0;
}

