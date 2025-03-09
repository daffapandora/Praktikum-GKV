#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); 
    
    glBegin(GL_POLYGON);
    float radius = 0.5;
    for(int i = 0; i < 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
    }
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
