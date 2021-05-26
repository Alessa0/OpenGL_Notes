#include<iostream>
#include <glut.h>


float yRot = 0;
GLfloat light_position[4] = { 0,0,0,1 };        //��λ��
GLfloat light_diffuse[4] = { 1,0,1,1 };        //�������ɫ
GLfloat light_direction[4] = { -1, -2, -1, 1 };    //��Դ�۹�Ʒ���
GLfloat light_change[3] = { 3,3,-1 };            //��Դ�ƶ�λ�á�

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // �����ɫ���ݺ�������ݣ�������
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();        //��ʼ�任����Ϊ��λ����

    glTranslated(0, -1, -5);    //ƽ��0,0,-5��Z������ƽ��5����λ

    glPushMatrix();        //ѹ�������趨��Դ��λ��
    glDisable(GL_LIGHTING);
    glRotatef(yRot, 0, 1, 0);    //��Դ����ת
    glTranslatef(light_change[0], light_change[1], light_change[2]);    //��Դ��λ��
    glTranslatef(light_position[0], light_position[1], light_position[2]);    //��Դλ��

    glutSolidSphere(0.1, 4, 4);//���ÿ⺯������һ���뾶Ϊ1�����塣��ʾ��Դ������
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
    light_direction[0] = -light_change[0];
    light_direction[1] = -light_change[1];
    light_direction[2] = -light_change[2];
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glPopMatrix();        //��Դ�������

    glPushMatrix();            //Ҫ����󣬻��Ƶ���
    glBegin(GL_QUADS);
    glVertex3f(-3, 0, 3);
    glVertex3f(3, 0, 3);
    glVertex3f(3, 0, -3);
    glVertex3f(-3, 0, -3);
    glEnd();
    glPopMatrix();            //����������

    glPushMatrix();            //ѹ��任������
    glutSolidSphere(1, 30, 30);//���ÿ⺯������һ���뾶Ϊ1�����塣
    glPopMatrix();            //��������

    glutSwapBuffers();            //��������������ʾͼ��
}

//��ʼ��
void init(void)
{
    //srand(0);    �������
    glClearColor(0.5, 0.5, 0.5, 0.0);    //������ɫ��Ϊ��ɫ����Ҳ����Ϊ�Ǳ�����ɫ��

    GLfloat light_param[] = { 1, 1, 1, 1.0 };    //��ʼ���������
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light_param);    //���ù�Ϊ�����⡣
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0); //���þ۹�ķ�ΧΪ45�ȡ�
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);    //���þ۹�Ƶľ۹�ǿ�ȡ�

    glMaterialfv(GL_FRONT, GL_SPECULAR, light_param);    //���ò��ʵ�����������
    //glMaterialfv(GL_FRONT, GL_AMBIENT, light_param);    //���ò��ʵĻ�������
    glMaterialf(GL_FRONT, GL_SHININESS, 64);    //���ò��ʵĸ߹�����


    glEnable(GL_LIGHTING);        //��������
    glEnable(GL_LIGHT0);        //����GL_LIGHTO��
    glCullFace(GL_BACK);        //�޳�����
    glEnable(GL_CULL_FACE);        //�����޳�
    glDepthFunc(GL_LEQUAL);        //��ȼ��ΪС�ڵ���
    glEnable(GL_DEPTH_TEST);    //������ȼ��
    glFrontFace(GL_CCW);        //������ʱ��Ϊ����

}

//�����ڴ�С�ı�ʱ��������������
void reshape(GLsizei w, GLsizei h)
{
    //����С˵��һ�£�����ģʽ�ǲ�ͬ�ģ����Ǹ�����һ������ͶӰ���
    //ֻ����ͶӰ����(ֻ��Ŀǰ�����Ŷ������ѧ���˿��ܾ�֪��Ϊʲô�ˡ�)

    glViewport(0, 0, w, h);        //�����ӿ�
    glMatrixMode(GL_PROJECTION);    //���þ���ģʽΪͶӰ�任����
    glLoadIdentity();                //��Ϊ��λ����
    gluPerspective(60, (GLfloat)w / h, 0, 1000);    //����ͶӰ����
    //glOrtho(-6.0, 6.0, -6.0 * h / w, 6.0* h / w, -10, 10);    //Ϊ�˲����Σ���Ҫ���Ϳ�ɱ���
    glMatrixMode(GL_MODELVIEW);        //���þ���ģʽΪ��ͼ����(ģ��)
    glLoadIdentity();                //��Ϊ��λ����
}

void Keyboard(unsigned char key, int x, int y)
{
}

//���ú���������ѭ������ʱ�ͻ�����������
void MyIdle(void)
{
   

 
        yRot += 0.5f;    //��ת�Ƕ�
        /*light_diffuse[0] = (rand() % 255) / 255.0;//̫�������ˡ�
        light_diffuse[1] = (rand() % 255) / 255.0;
        light_diffuse[2] = (rand() % 255) / 255.0;*/
        glutPostRedisplay();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);        //Opnegl��ʼ��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //������ʾģʽΪ˫���壬RGEBA

    glutInitWindowSize(800, 600);            //���ڴ�С
    glutInitWindowPosition(100, 100);        //����λ��
    glutCreateWindow("moving light");                //����һ������Ϊhello�Ĵ���
    init();                                //��ʼ����Դ,����һ��Ҫ�ڴ��������Ժ󣬲�Ȼ����Ч��
    glutDisplayFunc(display);                //���ڴ�С�ı�ʱ�Ļص�
    glutReshapeFunc(reshape);                //����ͼ��ʱ�Ļص�
    glutKeyboardFunc(Keyboard);
    glutIdleFunc(MyIdle);
    glutMainLoop();                            //��ѭ����
    return 0;
}