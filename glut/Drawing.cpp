#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glut.h>

#define PI 3.1415926

int iWidth = 600;
int iHeight = 600;

int iSize = 100;

float xRot = 0.0;
float yRot = 0.0;

void SetColor(int red, int green, int blue)
{
	glColor3ub(red, green, blue);
}

void RenderAHelix(float fRadiusInner, float fRadiusOuter,
	float fZStart = -60, float fZEnd = -10,
	int iNumofDot = 200)
{
	float Stepalpha = 6 * PI/iNumofDot;
	float StepZ = (fZEnd - fZStart) / iNumofDot;
	float StepRad = (fRadiusOuter - fRadiusInner) / iNumofDot;
	float x = 0, y = 0, z = 0;
	float alpha = 0;
	float Radius = fRadiusInner;
	z = fZStart;
	glPointSize(6);
	srand(6);
	glBegin(GL_LINE_STRIP);
	for (alpha = 0; alpha <6*PI; alpha+= Stepalpha,Radius+=StepRad)
	{
		x = Radius * cos(alpha);
		y = Radius * sin(alpha);

		int R = rand() % 255;
		int G = rand() % 255;
		int B = rand() % 255;
		SetColor(R,G,B);


		glVertex3f(x, y, z);
		z += 0.5f;
	}

	glEnd();
}

//class Point
//{
//public:
//	Point() {};
//	Point(double a, double b, double c) :x(a), y(b), z(c) {};
//public:
//	double x;
//	double y;
//	double z;
//
//};
//Point  translate(double r,double v,double u)
//{
//	double x = r*sin(PI * v) * cos(2*PI * u);
//	double y = r*sin(PI * v) * sin(2*PI * u);
//	double z =r* cos(PI * v);
//	return Point(x, y, z);
//
//
//}
//void RenderASphere(float fRadius, int iSlice = 10, int iStack = 10)
//{
//	double ustep = 1 / (double)iSlice, vstep = 1 / (double)iStack;
//	double u = 0, v = 0;
//	double r = fRadius;
//	//绘制下端三角形组
//	for (int i = 0; i < iSlice; i++)
//	{
//		SetColor(255,0,0);
//		glBegin(GL_LINE_LOOP);
//		Point a = translate(r,0, 0);
//		glVertex3d(a.x, a.y, a.z);
//		Point b = translate(r,u, vstep);
//		glVertex3d(b.x, b.y, b.z);
//		Point c = translate(r,u + ustep, vstep);
//		glVertex3d(c.x, c.y, c.z);
//		u += ustep;
//		glEnd();
//	}
//	//绘制中间四边形组
//	u = 0, v = vstep;
//	for (int i = 1; i < iStack - 1; i++)
//	{
//		for (int j = 0; j < iSlice; j++)
//		{
//			SetColor(0, 255, 0);
//			glBegin(GL_LINE_LOOP);
//			Point a = translate(r,u, v);
//			Point b = translate(r,u + ustep, v);
//			Point c = translate(r,u + ustep, v + vstep);
//			Point d = translate(r,u, v + vstep);
//			glVertex3d(a.x, a.y, a.z);
//			glVertex3d(b.x, b.y, b.z);
//			glVertex3d(c.x, c.y, c.z);
//			glVertex3d(d.x, d.y, d.z);
//			u += ustep;
//			glEnd();
//		}
//		v += vstep;
//	}
//	//绘制下端三角形组
//	u = 0;
//	for (int i = 0; i < iSlice; i++)
//	{
//		SetColor(0, 0, 255);
//		glBegin(GL_LINE_LOOP);
//		Point a = translate(r,0, 1);
//		Point b = translate(r,u, 1 - vstep);
//		Point c = translate(r,u + ustep, 1 - vstep);
//		glVertex3d(a.x, a.y, a.z);
//		glVertex3d(b.x, b.y, b.z);
//		glVertex3d(c.x, c.y, c.z);
//		glEnd();
//	}
//}
void RenderASphere( GLfloat radius, GLfloat M, GLfloat N)
{
	GLfloat xx=0, yy=0, zz=0;
	float step_z = PI / M;  //z方向每次步进的角度
		float step_xy = 2 * PI / N; //x,y平面每次步进的角度
		float x[4], y[4], z[4];  //用来存坐标

		float angle_z = 0.0;  //起始角度
		float angle_xy = 0.0;
	int i = 0, j = 0;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < M; i++)
	{
		angle_z = i * step_z; //每次步进step_z

			for (j = 0; j < N; j++)
			{
				angle_xy = j * step_xy;  //每次步进step_xy
					//整个的过程可以想象3D打印机，一层一层的画出来
					x[0] = radius * sin(angle_z) * cos(angle_xy);  //第一个小平面的第一个顶点坐标
					y[0] = radius * sin(angle_z) * sin(angle_xy);
				z[0] = radius * cos(angle_z);

				x[1] = radius * sin(angle_z + step_z) * cos(angle_xy);  	//第一个小平面的第二个顶点坐标，下面类似
					y[1] = radius * sin(angle_z + step_z) * sin(angle_xy);
				z[1] = radius * cos(angle_z + step_z);

				x[2] = radius * sin(angle_z + step_z) * cos(angle_xy + step_xy);
				y[2] = radius * sin(angle_z + step_z) * sin(angle_xy + step_xy);
				z[2] = radius * cos(angle_z + step_z);

				x[3] = radius * sin(angle_z) * cos(angle_xy + step_xy);
				y[3] = radius * sin(angle_z) * sin(angle_xy + step_xy);
				z[3] = radius * cos(angle_z);
			                                                         						//至此得到一个平面的4个顶点
					for (int k = 0; k < 4; k++)
					{
						glVertex3f(xx + x[k], yy + y[k], zz + z[k]);  			//画出这个平面
					}  
			} //循环画出这一层的平面，组成一个环
	}  //z轴++，画出剩余层
		glEnd();  
}



void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	//glutSolidTeapot(30);
	//glutWireTeapot(30);

	RenderAHelix(10, 60);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	RenderASphere(30,10,10);

	//RenderASphere(30);

	//glutWireSphere(30, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
}

void ChangeSize(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
	{
		glOrtho(-iSize, iSize, -iSize * height / width, iSize * height / width, -iSize, iSize);
	}
	else
	{
		glOrtho(-iSize * width / height, iSize * width / height, -iSize, iSize, -iSize, iSize);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void ProcessSpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		xRot -= 5.0f;
	}

	if (key == GLUT_KEY_DOWN)
	{
		xRot += 5.0f;
	}

	if (key == GLUT_KEY_LEFT)
	{
		yRot -= 5.0f;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		yRot += 5.0f;
	}

	glutPostRedisplay();
}

void InitWindow()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(iWidth, iHeight);

	glutCreateWindow("Ex5.2");

}

void Init()
{
	InitWindow();
}

void Process()
{

}

void Output()
{
	//int iSize = 200;
	glOrtho(-iSize, iSize, -iSize, iSize, -iSize, iSize);

	//glutKeyboardFunc();

	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(ProcessSpecialKeys);

	glutDisplayFunc(RenderScene);

	glutMainLoop();
}

int main(int argc, char* argv[])
{
	Init();
	Process();
	Output();

	return 1;
}