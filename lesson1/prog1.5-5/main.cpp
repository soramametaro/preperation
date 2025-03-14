#include <stdio.h>
#include <math.h>
#include <GL/glut.H>

//�����_�����O�̊֐�
void display(void){ 
  //�X�N���[���ƕϊ��s���������
  glClear(GL_COLOR_BUFFER_BIT); 
  glLoadIdentity();
  
  //�d�ׂ� x ���W
  float a[5] = {0, 0.5, -0.5, -0.5, 0.5};
  //�d�ׂ� y ���W
  float b[5] = {0, 0.5, 0.5, -0.5, -0.5};
  //�d�ׂ̒l
  float q[5] = {0.125, 0.25, -0.25, 0.25, -0.25};
  
  //�ۑ�͈ȉ��̕�����ǉ�����
  
  //�� 2�Ԃ��ɕ`�� (1�Ԃ��㏑�����Ȃ��悤��)
  //2�d for �ŐF��ς��Ȃ��珬���Ȑ����`��~���l�߂�
  int N = 500; //�����`�̐�
  
  
  //�� 1�Ԃ���ɕ`��
  //�~���̍��W�ɂ͔z����g���܂��傤 (�����͏\���傫�߂ɂ��Ă܂�)
  float x[100]; //���_�����S�Ŕ��a�� 0.1 �̉~�� x ���W 
  float y[100]; //���_�����S�Ŕ��a�� 0.1 �̉~�� y ���W
  
  int M  = 20; //20�p�`���炢�ɂ��܂��傤��
  float r = 0.1; //�~�̔��a
  //�z�� x,y �ɉ~�̍��W�� for ���ő��
  
  
  //���������~�������Ă��� (���S�̍��W�𑫂��ĉ~�̒��S�����炷)
  
  
  
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
  glClearColor (0.5, 0.5, 0.5, 1);

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

