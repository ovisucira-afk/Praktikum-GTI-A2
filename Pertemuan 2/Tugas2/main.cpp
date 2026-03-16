#include <GL/glut.h>
#include <math.h>

void car(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
	// Body Atas
	glPushMatrix();
        glTranslatef(-0.05, 0.25, 0.0);
        glColor3f(0.3f, 0.4f, 1.0f);
        glBegin(GL_QUAD_STRIP);
            glVertex3f(-0.3, -0.2, 0.0);
            glVertex3f(-0.2, 0.1, 0.0);
            glVertex3f(0.4, -0.2, 0.0);
            glVertex3f(0.3, 0.1, 0.0);
        glEnd();
    glPopMatrix();
    
    // Body Bawah
    glPushMatrix();
        glTranslatef(0.0, -0.1, 0.0);
        glColor3f(0.3f, 0.4f, 1.0f);
        glBegin(GL_QUADS);
            glVertex3f(-0.6, -0.15, 0.0);
            glVertex3f(0.6, -0.15, 0.0);
            glVertex3f(0.6, 0.15, 0.0);
            glVertex3f(-0.6, 0.15, 0.0);
        glEnd();
    glPopMatrix();

    // Jendela
    glPushMatrix();
        glTranslatef(0.12, 0.25, 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_STRIP);
            glVertex3f(-0.05, -0.15, 0.0);
            glVertex3f(-0.05, 0.05, 0.0);
            glVertex3f(0.18, -0.15, 0.0);
            glVertex3f(0.12, 0.05, 0.0);
        glEnd();
    glPopMatrix();
    
	// Roda Kiri
	#define PI 3.1415926535898
	glPushMatrix();
    	glTranslatef(-0.35, -0.3, 0.0); 
    	glColor3f(1.0f, 1.0f, 1.0f);
    	glBegin(GL_TRIANGLE_FAN);
    		GLint circle_points = 100;
    		int i;
    		float angle;
    		float radius = 0.15;
        	for (i = 0; i < circle_points; i++) {
            	angle = 2 * PI * i / circle_points;
            	glVertex2f(radius * cos(angle), radius * sin(angle));
        	}
    	glEnd();

    	glColor3f(0.0f, 0.0f, 0.0f); 
    	glBegin(GL_LINE_LOOP);
        	for (i = 0; i < circle_points; i++) {
            	angle = 2 * PI * i / circle_points;
            	glVertex2f(radius * cos(angle), radius * sin(angle));
        	}
    	glEnd();

    	glBegin(GL_LINES);
        	glVertex3f(-0.15, 0.0, 0.0); 
			glVertex3f(0.15, 0.0, 0.0);
        	glVertex3f(0.0, -0.15, 0.0); 
			glVertex3f(0.0, 0.15, 0.0);
    	glEnd();
	glPopMatrix();

	// Roda Kanan
	glPushMatrix();
    	glTranslatef(0.35, -0.3, 0.0); 
    	glColor3f(1.0f, 1.0f, 1.0f);
    	glBegin(GL_TRIANGLE_FAN);
        	for (i = 0; i < circle_points; i++) {
            	angle = 2 * PI * i / circle_points;
            	glVertex2f(radius * cos(angle), radius * sin(angle));
        	}
    	glEnd();

    	glColor3f(0.0f, 0.0f, 0.0f);
    	glBegin(GL_LINE_LOOP);
        	for (i = 0; i < circle_points; i++) {
            	angle = 2 * PI * i / circle_points;
            	glVertex2f(radius * cos(angle), radius * sin(angle));
        	}
    	glEnd();

    	glBegin(GL_LINES);
        	glVertex3f(-0.15, 0.0, 0.0); 
			glVertex3f(0.15, 0.0, 0.0);
        	glVertex3f(0.0, -0.15, 0.0); 
			glVertex3f(0.0, 0.15, 0.0);
    	glEnd();
	glPopMatrix();
	
	// Lampu
	glPushMatrix();
		glTranslatef(0.585, -0.05, 0.0);
		glPointSize(10.0f);
    	glBegin(GL_POINTS);
    		glColor3f(1.0f, 1.0f, 0.0f);
        	glVertex3f(0.0, 0.0, 0.0);
    	glEnd();
	glPopMatrix();
	
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Ovilia Suci Ramadhani_24060124120040");
    glutDisplayFunc(car);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}

