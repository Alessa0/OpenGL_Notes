#include <Windows.h>
#include <glut.h>


static GLfloat angle = 0.0f;
void myDisplay(void)
{
	glClearColor(0.3, 0.7, 0.5, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //������ɫ����Ȼ���     

	// ����͸��Ч����ͼ      
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, 1.0f, 1.0f, 20.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 12.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// ����̫����Դ������һ�ְ�ɫ�Ĺ�Դ   
	{
		GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //��Դ��λ������������ϵԲ�ģ����������ʽ
		GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //RGBAģʽ�Ļ����⣬Ϊ0
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //RGBAģʽ��������⣬ȫ�׹�
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  //RGBAģʽ�µľ���� ��ȫ�׹�
		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		//�����ƹ�
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
	}

	// ����̫���Ĳ��ʲ�����̫��    
	{
		GLfloat sun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //������ʵĻ�������ɫ��Ϊ0
		GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //������ʵ����������ɫ��Ϊ0
		GLfloat sun_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //������ʵľ��淴�����ɫ��Ϊ0
		GLfloat sun_mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊƫ��ɫ
		GLfloat sun_mat_shininess = 0.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);
		glutSolidSphere(3.0, 40, 32);
	}

	// �������Ĳ��ʲ����Ƶ���    
	{
		GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //������ʵĻ�������ɫ��ƭ��ɫ
		GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };  //������ʵ����������ɫ��ƫ��ɫ
		GLfloat earth_mat_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };   //������ʵľ��淴�����ɫ����ɫ
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊ0
		GLfloat earth_mat_shininess = 30.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glRotatef(angle, 0.0f, -1.0f, 0.0f);
		glTranslatef(7.0f, 0.0f, 0.0f);
		glutSolidSphere(3.0, 40, 32);
	}
	Sleep(10);
	glutSwapBuffers();
}

void myIdle(void)
{
	angle += 1.0f;
	if (angle >= 360.0f)
		angle = 0.0f;
	myDisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OpenGL������ʾ");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return 0;
}

