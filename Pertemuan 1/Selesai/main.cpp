// GL_QUAD_STRIP
#include <Gl/glut.h>

void QuadStrip(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.9, 0.2);
    glVertex2f(0.9, -0.2);
    glEnd();
	
	glFlush();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Ovilia Suci Ramadhani_24060124120040");
	glutDisplayFunc(QuadStrip);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}

