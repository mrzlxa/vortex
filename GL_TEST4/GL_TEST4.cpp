#include "stdafx.h"
#include <gl\glut.h>
 
// инициализация переменных цвета в 1.0
// треугольник - белый
float red=1.0f, blue=1.0f, green=1.0f;
 
// угол поворота
float angle = 0.0f;
 
void changeSize(int w, int h) {
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
}
 
void renderScene(void) {
 
	// очистить буфер цвета и глубины.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
	glLoadIdentity();
	// установить камеру
	gluLookAt( 0.0f, 0.0f, 10.0f,
		       0.0f, 0.0f,  0.0f,
		       0.0f, 1.0f,  0.0f);
	//поворот на заданную величину
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	// установить цвет модели
	glColor3f(red,green,blue);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-1.5f, 0.0f);
		glVertex3f( 0.0f, 2.0f, 0.0);
		glVertex3f( 2.0f,-1.5f, 0.0);
	glEnd();
 
	angle+=0.04f;
 
	glutSwapBuffers();
}
 
void processNormalKeys(unsigned char key, int x, int y) {
 
	if (key == 27)
		exit(0);
}
 
void processSpecialKeys(int key, int x, int y) {
 
	switch(key) {
		case GLUT_KEY_F1 :
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
	}
}
 
int main(int argc, char **argv) {
 
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Урок 4");
 
	// регистрация
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
 
	// наши новые функции
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
 
	// основной цикл
	glutMainLoop();
 
	return 1;
}