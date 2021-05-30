//#include<math.h>
//#include<stdlib.h>
//#include<stdio.h>
//#include <glut.h>
//
//
//#define POINT 1
//#define LINE 2
//#define RECT 3
//#define CIRCLE 4
//#define ELLIPSE 5
//
//#define RED 1
//#define GREEN 2
//#define BLUE 3
//#define WHITE 4
//#define EXIT 0
//#define LOAD -1
//#define SAVE -2
//#define CLEAR -3
//#define PI 3.14159
//int color =WHITE;
//int size = 4;
//int n = 100;
//int iBoradWidth = 800;
//int iBoradHeight = 800;
//
//
//int iMode = POINT;
//int iModeNum = 1;
//
//bool MouseLeftButtonDown = false;
//
//int ix, iy;
//
//
////点
//typedef struct SPoint
//{
//	float x, y;
//	int size, color;
//}  Spoint;
//typedef struct SPointList
//{
//	Spoint *points;
//	int pointsNum;
//	int memSize;
//}  SpointList;
////线
//typedef struct SLine
//{
//	Spoint start;
//	Spoint end;
//	float size;
//	int  color;
//}  SLine;
//typedef struct SLineList
//{
//	SLine* lines;
//	int linesNum;
//	int memSize;
//}  SLineList;
////矩形
//typedef struct SRect
//{
//	Spoint start;
//	Spoint end;
//	float size;
//	int  color;
//}  SRect;
//typedef struct SRectList
//{
//	SRect* rects;
//	int rectsNum;
//	int memSize;
//}  SRectList;
////圆
//typedef struct SCircle
//{
//	Spoint start;
//	Spoint range;
//	float size;
//	int  color;
//}  SCircle;
//typedef struct SCircleList
//{
//	SCircle* circles;
//	int circlesNum;
//	int memSize;
//}  SCircleList;
//typedef struct SEllipse
//{
//	Spoint start;
//	Spoint range;
//	GLfloat a = 0, b = 0;
//	float size;
//	int  color;
//}  SEllipse;
//typedef struct SEllipseList
//{
//	SEllipse* ellipse;
//	int ellipseNum;
//	int memSize;
//}  SEllipseList;
//
//SpointList pointlist = {NULL,0,100};
//SLineList linelist = { NULL,0,100 };
//SRectList rectlist = { NULL,0,100 };
//SCircleList circlelist = {NULL,0,100};
//SEllipseList ellipselist = { NULL,0,100 };
//
//
//
//
//void SetColor(int value)
//{
//	switch (value)
//	{
//	case RED :
//		{
//		glColor3f(1,0,0);
//		break;
//		}
//	case GREEN:
//	{
//		glColor3f(0, 1, 0);
//		break;
//	}
//	case BLUE:
//	{
//		glColor3f(0, 0, 1);
//		break;
//	}
//	case WHITE:
//	{
//		glColor3f(1, 1,1);
//		break;
//	}
//	}
//}
//void renderASphere(float r,int range)
//{
//	int i = 0;
//	float rad = r;
//	float alpha=0;
//	float alphaStep =2*PI/range;
//
//	float x, y;
//	glBegin(GL_POINTS);
//	for (alpha = 0; alpha <=2*PI; alpha+=alphaStep)
//	{
//		x = rad * cos(alpha);
//		y = rad * sin(alpha);
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//void RenderEllipse()
//{
//	for (int i = 0; i < ellipselist.ellipseNum; i++)
//	{
//		SetColor(ellipselist.ellipse[i].color);
//
//		ellipselist.ellipse[i].a = fabs(ellipselist.ellipse[i].start.x - ellipselist.ellipse[i].range.x);
//		ellipselist.ellipse[i].b= fabs(ellipselist.ellipse[i].start.y - ellipselist.ellipse[i].range.y);
//		glBegin(GL_TRIANGLE_FAN);
//		
//		for (int j = 0; j < (2*n); j++)
//		{
//			GLfloat o = 2.0f * PI * (float)j / 200.0f;
//			float dx = ellipselist.ellipse[i].a * cos(o);
//			float dy= ellipselist.ellipse[i].b * sin(o);
//			glVertex2f(ellipselist.ellipse[i].start.x + dx, ellipselist.ellipse[i].start.y + dy);
//		}
//		glEnd();
//	}
//}
//void RenderCirecle()
//{
//	
//
//	for (int i = 0; i <circlelist.circlesNum; i++)
//	{
//		GLfloat R = sqrt(pow((circlelist.circles[i].start.x- circlelist.circles[i].range.x),2)
//			+ pow((circlelist.circles[i].start.y - circlelist.circles[i].range.y),2));
//				SetColor(circlelist.circles[i].color);
//			
//				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//				glBegin(GL_POLYGON);
//				
//				for (int j = 0; j < n; j++)
//				{
//					float o = 2.0f * PI * (float)j / 100.0f;
//					float dx = R * cos(o);
//					float dy = R * sin(o);
//					glVertex2f(circlelist.circles[i].start.x+dx, circlelist.circles[i].start.y+dy);
//				}
//					
//
//				glEnd();
//
//		
//	}
//}
//
//
//
//
//
//void RenderRect()
//{
//	int i;
//	for (i = 0; i < rectlist.rectsNum; i++)
//	{
//		SetColor(rectlist.rects[i].color);
//		glPointSize(rectlist.rects[i].size);
//
//		glBegin(GL_QUADS);
//		glVertex2i(rectlist.rects[i].start.x, rectlist.rects[i].start.y);
//		glVertex2i(rectlist.rects[i].start.x, rectlist.rects[i].end.y);
//		glVertex2i(rectlist.rects[i].end.x, rectlist.rects[i].end.y);
//		glVertex2i(rectlist.rects[i].end.x, rectlist.rects[i].start.y);
//		glEnd();
//		glutSwapBuffers();
//	}
//	
//}
//void RenderLines()
//{
//	int i;
//	for (i = 0; i < linelist.linesNum; i++)
//	{
//		SetColor(linelist.lines[i].color);
//		glPointSize(linelist.lines[i].size);
//		glBegin(GL_LINES);
//		glVertex2i(linelist.lines[i].start.x, linelist.lines[i].start.y);
//		glVertex2i(linelist.lines[i].end.x, linelist.lines[i].end.y);
//		glEnd();
//	
//		
//	}
//}
//void RenderPoint()
//{
//	int i;
//	for (i = 0; i < pointlist.pointsNum; i++)
//	{
//		SetColor(pointlist.points[i].color);
//		glPointSize(pointlist.points[i].size);
//		glBegin(GL_POINTS);
//		glVertex2f(pointlist.points[i].x, pointlist.points[i].y);
//
//		glEnd();
//	}
//
//}
//void Display( )
// {
//	     glClear(GL_COLOR_BUFFER_BIT);
//		 SetColor(color);
//		 //glRectf(-1.0f, 0.5f, 1.0f, -0.5f);
//		 glPointSize(size);
//		 renderASphere(150,100);
//		 RenderPoint();
//		 RenderLines();
//		 RenderRect();
//		 RenderCirecle();
//		 RenderEllipse();
//	     glFlush();
//	 }
//
//void SaveFile(const char*name)
//{
//	FILE* file = fopen(name,"w");
//	if (!file)
//	{
//		printf("erro");
//		exit(0);
//	}
//	fprintf(file,"%d\n",pointlist.pointsNum);
//	int i=0;
//	while (i<pointlist.pointsNum)
//	{
//		fprintf(file, "%f %f %d %d\n ", &(pointlist.points[i].x), &(pointlist.points[i].y), &(pointlist.points[i].color), &(pointlist.points[i].size));
//		i++;
//	}
//	fclose(file);
//}
//void LoadFile(const char* name)
//{
//	FILE* file = fopen(name, "r");
//	if (!file)
//	{
//		printf("erro");
//		exit(0);
//	}
//	fscanf(file,"%d",&(pointlist.pointsNum));
//	int i = 0;
//	while (i< pointlist.pointsNum)
//	{
//		fscanf(file, "%f %f  %d %d", &(pointlist.points[i].x), &(pointlist.points[i].y), &(pointlist.points[i].color), &(pointlist.points[i].size));
//		i++;
//	}
//
//	fclose(file);
//
//}
//void ProcessMajorMenu(int value)
//{
//	switch (value)
//	{
//	
//	case EXIT:
//	{
//		exit(0);
//	}
//	case LOAD:
//	{
//		LoadFile("file.txt");
//		glutPostRedisplay();
//		break;
//	}
//	case SAVE:
//	{
//		SaveFile("file.txt");
//		break;
//	}
//	case CLEAR:
//	{
//		glClear(GL_COLOR_BUFFER_BIT);
//		break;
//	}
//	
//	}
//}
//void colorMenuClick(int index)
//{
//	if (color!=index)
//	{
//		switch (color)
//		{
//		case RED:glutChangeToMenuEntry(color,"红色",color);
//			break;
//		case GREEN:glutChangeToMenuEntry(color, "绿色", color);
//			break;
//		case BLUE:glutChangeToMenuEntry(color, "蓝色", color);
//			break;
//		case WHITE:glutChangeToMenuEntry(color, "白色", color);
//			break;
//		}
//		color = index;
//		switch (index)
//		{
//		case RED:
//		{
//			glutChangeToMenuEntry(color, "红色<", color);
//			glutPostRedisplay();
//			break;
//		}
//		case GREEN:
//		{
//			glutChangeToMenuEntry(color, "绿色<", color);
//			glutPostRedisplay();
//			break;
//		}
//		case BLUE:
//		{
//			glutChangeToMenuEntry(color, "蓝色<", color);
//			glutPostRedisplay();
//			break;
//		}
//		case WHITE:
//		{
//			glutChangeToMenuEntry(color, "白色<", color);
//			glutPostRedisplay();
//			break;
//		}
//	
//		}
//	}
//	
//}
//void sizeMenuClick(int index)
//{
//	if (size != index)
//	{
//		switch (size)
//		{
//		case 1:glutChangeToMenuEntry(size, "1", size);
//			break;
//		case 2:glutChangeToMenuEntry(size, "2", size);
//			break;
//		case 3:glutChangeToMenuEntry(size, "3", size);
//			break;
//		case 4:glutChangeToMenuEntry(size, "4", size);
//			break;
//		case 5:glutChangeToMenuEntry(size, "5", size);
//			break;
//		case 6:glutChangeToMenuEntry(size, "6", size);
//			break;
//		}
//		size = index;
//		switch (index)
//		{
//		case 1:
//		{
//			glutChangeToMenuEntry(size, "1<", size);
//			glutPostRedisplay();
//			break;
//		}
//		case 2:
//		{
//			glutChangeToMenuEntry(size, "2", size);
//			glutPostRedisplay();
//			break;
//		}
//		case 3:
//		{
//			glutChangeToMenuEntry(size, "3<", size);
//			glutPostRedisplay();
//			break;
//		}
//		case 4:
//		{
//			glutChangeToMenuEntry(size, "4<", size);
//			glutPostRedisplay();
//			break;
//		}
//		case 5:
//		{
//			glutChangeToMenuEntry(size, "5<", size);
//			glutPostRedisplay();
//			break;
//		}
//		case 6:
//		{
//			glutChangeToMenuEntry(size, "6<", size);
//			glutPostRedisplay();
//			break;
//		}
//		}
//	}
//}
//
//void modeMenuClick(int index)
//{
//	if (iMode!= index)
//	{
//		switch (iMode)
//		{
//		case 1:glutChangeToMenuEntry(iMode, "点", iMode);
//			break;
//		case 2:glutChangeToMenuEntry(iMode, "线", iMode);
//			break;
//		case 3:glutChangeToMenuEntry(iMode, "矩形", iMode);
//			break;
//		case 4:glutChangeToMenuEntry(iMode, "圆", iMode);
//			break;
//		case 5:glutChangeToMenuEntry(iMode, "椭圆", iMode);
//			break;
//
//		}
//		iMode = index;
//		switch (index)
//		{
//		case 1:
//		{
//			glutChangeToMenuEntry(index, "点<", index);
//			glutPostRedisplay();
//			break;
//		}
//		case 2:
//		{
//			glutChangeToMenuEntry(index, "线<", index);
//			if (iModeNum<LINE)
//			{
//				iModeNum = LINE;
//			}
//			glutPostRedisplay();
//			break;
//		}
//		case 3:
//		{
//			glutChangeToMenuEntry(index, "矩形<", iMode);
//			if (iModeNum < RECT)
//			{
//				iModeNum = RECT;
//			}
//			glutPostRedisplay();
//			break;
//		}
//		case 4:
//		{
//			glutChangeToMenuEntry(index, "圆<", iMode);
//			if (iModeNum < CIRCLE)
//			{
//				iModeNum = CIRCLE;
//			}
//			glutPostRedisplay();
//			break;
//		}
//		case 5:
//		{
//			glutChangeToMenuEntry(index, "椭圆<", iMode);
//			if (iModeNum < ELLIPSE)
//			{
//				iModeNum = ELLIPSE;
//			}
//			glutPostRedisplay();
//			break;
//		}
//		}
//	}
//}
//void InitMenu()
//{
//	int modeMenuID = glutCreateMenu(modeMenuClick);
//	glutAddMenuEntry("点<", POINT);
//	glutAddMenuEntry("线", LINE);
//	glutAddMenuEntry("矩形", RECT);
//	glutAddMenuEntry("圆", CIRCLE);
//	glutAddMenuEntry("椭圆", ELLIPSE);
//
//
//	int colorMenuID= glutCreateMenu(colorMenuClick);
//	glutAddMenuEntry("红", 1);
//	glutAddMenuEntry("绿", 2);
//	glutAddMenuEntry("蓝", 3);
//	glutAddMenuEntry("白<", 4);
//	int SizeMenuID = glutCreateMenu(sizeMenuClick);
//	glutAddMenuEntry("1", 1);
//	glutAddMenuEntry("2", 2);
//	glutAddMenuEntry("3", 3);
//	glutAddMenuEntry("4<", 4);
//	glutAddMenuEntry("5", 5);
//	glutAddMenuEntry("6", 6);
//
//	int majorMenuID = glutCreateMenu(ProcessMajorMenu);
//
//	glutAddSubMenu("颜色",colorMenuID);
//	glutAddSubMenu("形状", modeMenuID);
//
//
//	glutAddSubMenu("大小", SizeMenuID);
//	glutAddMenuEntry("清屏", CLEAR);
//	glutAddMenuEntry("加载", LOAD);
//	glutAddMenuEntry("保存", SAVE);
//
//	glutAddMenuEntry("退出", 5);
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	
//	
//
//}
//
//void InitWindow()
//{
//	glutInitWindowSize(iBoradWidth,iBoradHeight);
//	glutCreateWindow("simple");
//
//}
//void MouseClick(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		
//			if (iMode == POINT&& state == GLUT_DOWN)
//			{
//				MouseLeftButtonDown = true;
//				pointlist.points[pointlist.pointsNum].x = x/2;
//				pointlist.points[pointlist.pointsNum].y = y/2;
//				pointlist.points[pointlist.pointsNum].color = color;
//				pointlist.points[pointlist.pointsNum].size = size;
//
//				pointlist.pointsNum++;
//				glutPostRedisplay();
//			}
//			else if (iMode == LINE && state == GLUT_DOWN)
//			{
//				MouseLeftButtonDown = true;
//				linelist.lines[linelist.linesNum].start.x = x / 2;
//				linelist.lines[linelist.linesNum].start.y = y / 2;
//				linelist.lines[linelist.linesNum].end.x = x / 2;
//				linelist.lines[linelist.linesNum].end.y = y / 2;
//				linelist.lines[linelist.linesNum].color = color;
//				linelist.lines[linelist.linesNum].size = size;
//				linelist.linesNum++;
//				glutPostRedisplay();
//			}
//			else if (iMode == RECT && state == GLUT_DOWN)
//			{
//				MouseLeftButtonDown = true;
//				rectlist.rects[rectlist.rectsNum].start.x = x / 2;
//				rectlist.rects[rectlist.rectsNum].start.y = y / 2;
//				rectlist.rects[rectlist.rectsNum].end.x = x / 2;
//				rectlist.rects[rectlist.rectsNum].end.y = y / 2;
//				rectlist.rects[rectlist.rectsNum].color = color;
//				rectlist.rects[rectlist.rectsNum].size = size;
//				rectlist.rectsNum++;
//				glutPostRedisplay();
//			}
//			else if (iMode == CIRCLE && state == GLUT_DOWN)
//			{
//				MouseLeftButtonDown = true;
//				circlelist.circles[circlelist.circlesNum].start.x = x / 2;
//				circlelist.circles[circlelist.circlesNum].start.y = y / 2;
//				circlelist.circles[circlelist.circlesNum].range.x = x / 2;
//				circlelist.circles[circlelist.circlesNum].range.y = y / 2;
//				circlelist.circles[circlelist.circlesNum].color = color;
//				circlelist.circles[circlelist.circlesNum].size = size;
//				circlelist.circlesNum++;
//				glutPostRedisplay();
//			}
//			else if (iMode==ELLIPSE && state == GLUT_DOWN)
//			{
//				MouseLeftButtonDown = true;
//				ellipselist.ellipse[ellipselist.ellipseNum].start.x= x / 2;
//				ellipselist.ellipse[ellipselist.ellipseNum].start.y = y / 2;
//				ellipselist.ellipse[ellipselist.ellipseNum].color = color;
//				ellipselist.ellipse[ellipselist.ellipseNum].size = size;
//				ellipselist.ellipseNum++;
//				glutPostRedisplay();
//			}
//
//			else if (state == GLUT_UP)
//			{
//				MouseLeftButtonDown = false;
//			}
//			glutPostRedisplay();
//	}
//}
//void MouseDownMoveEvent(int x,int y)
//{
//	if (MouseLeftButtonDown)
//	{
//		if (iMode == LINE)
//		{
//			linelist.lines[linelist.linesNum - 1].end.x = x / 2;
//			linelist.lines[linelist.linesNum - 1].end.y = y / 2;
//			glutPostRedisplay();
//		}
//		else if (iMode == RECT)
//		{
//			rectlist.rects[rectlist.rectsNum - 1].end.x = x / 2;
//			rectlist.rects[rectlist.rectsNum - 1].end.y = y / 2;
//			glutPostRedisplay();
//		}
//		else if (iMode == CIRCLE)
//		{
//			circlelist.circles[circlelist.circlesNum - 1].range.x = x / 2;
//			circlelist.circles[circlelist.circlesNum - 1].range.y = y / 2;
//			glutPostRedisplay();
//		}
//		else if (iMode==ELLIPSE)
//		{
//			ellipselist.ellipse[ellipselist.ellipseNum - 1].range.x = x / 2;
//			ellipselist.ellipse[ellipselist.ellipseNum - 1].range.y = y/ 2;
//			glutPostRedisplay();
//		}
//	
//	}
//}
//void InitMouseInput()
//{
//	glutMouseFunc(MouseClick);
//	glutMotionFunc(MouseDownMoveEvent);
//	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
//}
//void InitPointList()
//{
//	pointlist.points = (SPoint*)malloc(pointlist.memSize*sizeof(SPoint));
//	if (pointlist.points==NULL)
//	{
//		printf("没有点");
//			exit(0);
//	}
//
//}
//void InitLineList()
//{
//	linelist.lines = (SLine*)malloc(linelist.memSize * sizeof(SLine));
//	if (linelist.lines == NULL)
//	{
//		printf("没有点");
//		exit(0);
//	}
//
//}
//void InitRectList()
//{
//	rectlist.rects = (SRect*)malloc(rectlist.memSize*sizeof(SRect));
//	if (rectlist.rects == NULL)
//	{
//		printf("没有点");
//		exit(0);
//	}
//}
//void InitCircleList()
//{
//	circlelist.circles = (SCircle*)malloc(circlelist.memSize * sizeof(SCircle));
//	if (circlelist.circles == NULL)
//	{
//		printf("没有点");
//		exit(0);
//	}
//}
//void InitEllipseList()
//{
//	ellipselist.ellipse = (SEllipse*)malloc(ellipselist.memSize * sizeof(SEllipse));
//	if (ellipselist.ellipse == NULL)
//	{
//		printf("没有点");
//		exit(0);
//	}
//}
//void InitData()
//{
//	InitLineList();
//	InitPointList();
//	InitRectList();
//	InitCircleList();
//	InitEllipseList();
//}
//void init()
//{
//	InitWindow();
//	InitData();
//	InitMenu();
//	InitMouseInput();
//
//}
//void InPut()
//{
//
//}
//void OutPut()
//{
//	gluOrtho2D(0,400,400,0);
//	glutDisplayFunc(&Display);
//	glutMainLoop();
//}
//void process()
//{
//
//}
// int main(int argc, char* argv[])
// {
//	 init();
//	 InPut();
//	 OutPut();
//	 process();
//
//   return 0;
// }