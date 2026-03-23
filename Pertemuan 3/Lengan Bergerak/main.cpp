#include <GL/glut.h>
#include <stdlib.h>

// Lengan
static int shoulder = 0, elbow = 0;

// Pergelangan tangan
static int wrist = 0;

// 2 ruas jari
static int f1_base=0,f1_tip=0;
static int f2_base=0,f2_tip=0;
static int f3_base=0,f3_tip=0;
static int f4_base=0,f4_tip=0;
static int t_base=0,t_tip=0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(float y, int base, int tip) {
    glPushMatrix();
    	glTranslatef(0.0, y, 0.0);

    	// ruas 1
    	glRotatef(base, 0, 0, 1);
    	glTranslatef(0.25, 0.0, 0.0);
    	glPushMatrix();
        	glScalef(0.5, 0.1, 0.1);
        	glutWireCube(1.0);
    	glPopMatrix();

   		// ruas 2
    	glTranslatef(0.25, 0.0, 0.0);
    	glRotatef(tip, 0, 0, 1);
    	glTranslatef(0.25, 0.0, 0.0);
    	glPushMatrix();
        	glScalef(0.5, 0.1, 0.1);
        	glutWireCube(1.0);
    	glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    	// Shoulder
    	glTranslatef(-1.0, 0.0, 0.0);
    	glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
    	glTranslatef(1.0 , 0.0, 0.0);
    	glPushMatrix();
        	glScalef(2.0, 0.4, 1.0);
        	glutWireCube(1.0);
    	glPopMatrix();

    	// Elbow
    	glTranslatef(1.0, 0.0, 0.0);
    	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
    	glTranslatef(1.0, 0.0, 0.0);
    	glPushMatrix();
        	glScalef(2.0, 0.4, 1.0);
        	glutWireCube(1.0);
    	glPopMatrix();

    	// Wrist
   		glTranslatef(1,0,0);
    	glRotatef(wrist,0,0,1);

    	// Palm
    	glPushMatrix();
        	glScalef(0.6,0.6,0.6);
        	glutWireCube(1);
    	glPopMatrix();
    	glTranslatef(0.5,0,0);

    	// 4 jari
    	drawFinger( 0.225, f1_base, f1_tip);
    	drawFinger( 0.075, f2_base, f2_tip);
    	drawFinger(-0.075, f3_base, f3_tip);
    	drawFinger(-0.225, f4_base, f4_tip);

    	// Ibu jari
    	glPushMatrix();
        	glTranslatef(0,-0.35,0);
        	glRotatef(-40,0,0,1);
        	drawFinger(0, t_base, t_tip);
    	glPopMatrix();
    	
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 's': 
		shoulder = (shoulder + 5); 
		break;
    case 'S': 
		shoulder-=5; 
		break;

    case 'e': 
		elbow+=5; 
		break;
    case 'E': 
		elbow-=5; 
		break;

    case 'w': 
		wrist+=5; 
		break;
    case 'W': 
		wrist-=5; 
		break;

    // Jari 1
    case '1': 
		f1_base+=5; 
		break;
    case '!': 
		f1_tip+=5; 
		break;

    // Jari 2
    case '2': 
		f2_base+=5; 
		break;
    case '@': 
		f2_tip+=5; 
		break;

    // Jari 3
    case '3': 
		f3_base+=5; 
		break;
    case '#': 
		f3_tip+=5; 
		break;

    // Jari 4
    case '4': 
		f4_base+=5; 
		break;
    case '$': 
		f4_tip+=5; 
		break;

    // Ibu jari
    case '5': 
		t_base+=5; 
		break;
    case '%': 
		t_tip+=5; 
		break;

    case 27: 
		exit(0);
		break; 
		
	default: 
		break;
    }
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(900,600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Ovilia Suci Ramadhani");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

