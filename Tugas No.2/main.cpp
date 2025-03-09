#include <GL/glut.h>
#include <math.h>

void drawCircle(float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * i / segments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawSun() {
    glColor3f(1.0, 0.8, 0.0); 
    glPushMatrix();
    glTranslatef(0.8, 0.8, 0.0); 
    drawCircle(0.15, 36);
    glPopMatrix();
}

void drawCloud(float x, float y) {
    glColor3f(0.9, 0.9, 0.9); // Abu-abu muda
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    drawCircle(0.1, 24);  // Lingkaran utama
    glTranslatef(0.1, 0.05, 0.0);
    drawCircle(0.08, 24);  // Lingkaran samping kanan
    glTranslatef(-0.2, 0.02, 0.0);
    drawCircle(0.08, 24);  // Lingkaran samping kiri
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar Matahari
    drawSun();

    // Gambar Awan 
    drawCloud(-0.7, 0.7);
    drawCloud(-0.3, 0.8);
    drawCloud(0.2, 0.6);

    // Mobil
    glPushMatrix(); 

    // Badan mobil (kotak)
    glColor3f(0.2, 0.4, 0.8); // Biru
    glBegin(GL_POLYGON);
        glVertex2f(-0.6, 0.0);
        glVertex2f(0.6, 0.0);
        glVertex2f(0.6, 0.3);
        glVertex2f(0.3, 0.3);
        glVertex2f(0.2, 0.6);
        glVertex2f(-0.4, 0.6);
        glVertex2f(-0.6, 0.3);
    glEnd();

    // Jendela depan
    glColor3f(0.8, 0.8, 1.0); // Light blue
    glBegin(GL_POLYGON);
        glVertex2f(-0.38, 0.32);
        glVertex2f(0.18, 0.32);
        glVertex2f(0.18, 0.58);
        glVertex2f(-0.38, 0.58);
    glEnd();

    // Lampu depan
    glColor3f(1.0, 1.0, 0.0); // Kuning
    glBegin(GL_POLYGON);
        glVertex2f(-0.58, 0.1);
        glVertex2f(-0.54, 0.1);
        glVertex2f(-0.54, 0.2);
        glVertex2f(-0.58, 0.2);
    glEnd();

    // Lampu belakang
    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_POLYGON);
        glVertex2f(0.56, 0.1);
        glVertex2f(0.58, 0.1);
        glVertex2f(0.58, 0.2);
        glVertex2f(0.56, 0.2);
    glEnd();

    // Roda Depan
    glPushMatrix();
    glTranslatef(-0.4, -0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1); // Ban luar hitam
    drawCircle(0.15, 36);
    glColor3f(0.8, 0.8, 0.8); // Pelek abu-abu
    drawCircle(0.08, 36);
    glColor3f(0.4, 0.4, 0.4); // Pusat roda
    drawCircle(0.02, 36);
    glPopMatrix();

    // Roda Belakang
    glPushMatrix();
    glTranslatef(0.4, -0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    drawCircle(0.15, 36);
    glColor3f(0.8, 0.8, 0.8);
    drawCircle(0.08, 36);
    glColor3f(0.4, 0.4, 0.4);
    drawCircle(0.02, 36);
    glPopMatrix();

    glPopMatrix(); // Akhir stack utama mobil

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background putih
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 2D dengan Matahari dan Awan");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

