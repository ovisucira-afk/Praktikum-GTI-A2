#include <windows.h>
#include <math.h>
#include <GL/glut.h>

// Kamera
float angle = 0.0f;
float deltaAngle = 0.0f;

float x = 0.0f; // posisi awal kamera kanan/kiri
float y = 3.0f; // posisi awal tinggi kamera 
float z = 15.0f; // posisi awal kejauhan kamera 

float lx = 0.0f; // arah pandang kamera ke arah sumbu -z
float ly = 0.0f;
float lz = -1.0f;

int deltaMove = 0;
int w, h;
float ratio;

// Lighting
const GLfloat light_ambient[]  = {0.3f,0.3f,0.3f,1.0f};
const GLfloat light_diffuse[]  = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[] = {0.0f,10.0f,10.0f,1.0f}; // posisi lampu di atas mobil

// Reshape
void Reshape(int w1, int h1){ // resize window
    if(h1 == 0) h1 = 1;

    w = w1;
    h = h1;

    ratio = 1.0f * w / h; // rasio layar

    glMatrixMode(GL_PROJECTION); // 3D dilayar 2D
    glLoadIdentity(); // menghapus transformasi sebelumnya
    glViewport(0,0,w,h); // mulai dari kiri atas (0,0), sebesar window (w,h)
    gluPerspective(45, ratio, 0.1, 1000); // 45 sudut pandang, rasio layar agar tidak gepeng, 0.1 objek terdekat, 1000 objek terjauh
    glMatrixMode(GL_MODELVIEW); // translasi, rotasi, posisi kamera, scaling
}

// Kamera
void orientMe(float ang){ // memutar kamera
    lx = sin(ang); // putar kamera
    lz = -cos(ang);

    glLoadIdentity();
    gluLookAt(
        x,y,z, // tempat kamera berada
        x+lx,y+ly,z+lz, // arah pandang kamera
        0.0f,1.0f,0.0f // menentukan arah atas adalah sumbu Y
    );
}

void moveMeFlat(int i){
    x = x + i*(lx)*0.2f; // maju & mundur
    z = z + i*(lz)*0.2f; // 1 maju, -1 mundur

    glLoadIdentity();
    gluLookAt(
        x,y,z,
        x+lx,y+ly,z+lz,
        0.0f,1.0f,0.0f
    );
}

// Grid
void Grid(){
    float i;

    glDisable(GL_LIGHTING); // tanpa lighting
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_LINES); // garis lantai
    for(i=-50;i<=50;i+=1){ // gambar garis horizontal & vertikal
        glVertex3f(i,0,-50);
        glVertex3f(i,0,50);
        glVertex3f(-50,0,i);
        glVertex3f(50,0,i);
    }
    glEnd();
    glEnable(GL_LIGHTING); 
}

// Roda
void roda(){
    glPushMatrix();
    glColor3f(0.1f,0.1f,0.1f);
    glScalef(1.0f,1.0f,0.5f); // scaling bola
    glutSolidSphere(0.6,20,20); // bola
    glPopMatrix();
}

// Body Mobil
void badanMobil(){
    // Body bawah
    glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
    glScalef(4.5f,1.0f,2.0f); // memperbesar objek
    glutSolidCube(1); // kubus
    glPopMatrix();

    // Body atas
    glPushMatrix();
    glTranslatef(0.0f,0.9f,0.0f); // dipindahkan ke atas
    glColor3f(0.0f,0.8f,0.0f);
    glScalef(2.5f,1.0f,2.0f);
    glutSolidCube(1);
    glPopMatrix();
}

// Jendela
void jendela(){
    glColor3f(0.3f,0.7f,1.0f);
    
    // kiri
    glPushMatrix();
    glTranslatef(0.0f,0.9f,1.01f); // dipindah ke atas
    glScalef(1.8f,0.6f,0.05f); // dipipihkan
    glutSolidCube(1);
    glPopMatrix();

    // kanan
    glPushMatrix();
    glTranslatef(0.0f,0.9f,-1.01f);
    glScalef(1.8f,0.6f,0.05f);
    glutSolidCube(1);
    glPopMatrix();

    // depan
    glPushMatrix();
    glTranslatef(-1.26f,0.9f,0.0f);
    glRotatef(90,0,1,0);
    glScalef(1.8f,0.6f,0.05f);
    glutSolidCube(1);
    glPopMatrix();

    // belakang
    glPushMatrix();
    glTranslatef(1.26f,0.9f,0.0f);
    glRotatef(90,0,1,0);
    glScalef(1.8f,0.6f,0.05f);
    glutSolidCube(1);
    glPopMatrix();
}

// lampu
void lampu(){
    // lampu depan kiri
    glPushMatrix();
    glTranslatef(-2.3f,0.0f,0.6f);
    glColor3f(1.0f,1.0f,0.0f);
    glutSolidSphere(0.2,20,20); // bola kecil
    glPopMatrix();

    // lampu depan kanan
    glPushMatrix();
    glTranslatef(-2.3f,0.0f,-0.6f);
    glColor3f(1.0f,1.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    // lampu belakang kiri
    glPushMatrix();
    glTranslatef(2.3f,0.0f,0.6f);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    // lampu belakang kanan
    glPushMatrix();
    glTranslatef(2.3f,0.0f,-0.6f);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
}

// Mobil 3D
void mobil3D(){
    glPushMatrix();
    glTranslatef(0.0f,1.0f,0.0f);

    // badan
    badanMobil();

    // jendela
    jendela();

    // lampu
    lampu();

    // roda depan kiri
    glPushMatrix();
    glTranslatef(-1.5f,-0.7f,1.2f);
    roda();
    glPopMatrix();

    // roda depan kanan
    glPushMatrix();
    glTranslatef(-1.5f,-0.7f,-1.2f);
    roda();
    glPopMatrix();

    // roda belakang kiri
    glPushMatrix();
    glTranslatef(1.5f,-0.7f,1.2f);
    roda();
    glPopMatrix();

    // roda belakang kanan
    glPushMatrix();
    glTranslatef(1.5f,-0.7f,-1.2f);
    roda();
    glPopMatrix();
    glPopMatrix();
}

// Display
void display(){
    if(deltaMove) // maju mundur
        moveMeFlat(deltaMove);

    if(deltaAngle){ // berputar
        angle += deltaAngle;
        orientMe(angle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // mebersihkan layar & menghapus depth sebelumnya
    glLoadIdentity();
    gluLookAt(
        x,y,z,
        x+lx,y+ly,z+lz,
        0.0f,1.0f,0.0f
    );

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    Grid();
    mobil3D();
    glutSwapBuffers(); // agar animasi halus dan tidak berkedip
}

// Keyboard
void pressKey(int key, int xx, int yy){
    switch(key){
        case GLUT_KEY_LEFT : // melihat kiri
            deltaAngle = -0.01f;
            break;

        case GLUT_KEY_RIGHT : // melihat kanan
            deltaAngle = 0.01f;
            break;

        case GLUT_KEY_UP : // melihat atas
            deltaMove = 1;
            break;

        case GLUT_KEY_DOWN : // melihat bawah
            deltaMove = -1;
            break;
    }
}

void releaseKey(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT :
            deltaAngle = 0.0f;
            break;

        case GLUT_KEY_RIGHT :
            deltaAngle = 0.0f;
            break;

        case GLUT_KEY_UP :
            deltaMove = 0;
            break;

        case GLUT_KEY_DOWN :
            deltaMove = 0;
            break;
    }
}

// Lighting
void lighting(){
    glEnable(GL_DEPTH_TEST); // objek dekat menutupi objek jauh
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING); // mengaktifkan cahaya
    glEnable(GL_LIGHT0); // sumber cahaya utama
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); // cahaya umum seluruh ruangan
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); // cahaya utama yang mengenai objek
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); // pantulan mengkilap
}

void init(){
    glClearColor(0.1f,0.1f,0.1f,1.0f);
    glShadeModel(GL_SMOOTH);
    lighting();
}

// Main
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(100,100); 
    glutInitWindowSize(800,600);
    glutCreateWindow("Ovilia Suci Ramadhani-24060124120040");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutIgnoreKeyRepeat(1);
    init();
    glutMainLoop();
    return 0;
}
