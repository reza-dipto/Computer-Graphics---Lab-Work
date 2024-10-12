#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int windowWidth = 800;
 int windowHeight = 800 ;
double eyeX=7.0, eyeY=2.0, eyeZ=15.0, refX = 0, refY=0,refZ=0;
double theta = 180.0, y = 1.36, z = 7.97888, a=2;
bool flagScale = false;
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'w': // move eye point upwards along Y axis
        eyeY+=1.0;
        break;
    case 's': // move eye point downwards along Y axis
        eyeY-=1.0;
        break;
    case 'a': // move eye point left along X axis
        eyeX-=1.0;
        break;
    case 'd': // move eye point right along X axis
        eyeX+=1.0;
        break;
    case 'o':  //zoom out
        eyeZ+=1;
        break;
    case 'i': //zoom in
        eyeZ-=1;
        break;
    case 'q': //back to default eye point and ref point
            eyeX=7.0; eyeY=2.0; eyeZ=15.0;
            refX=0.0; refY=0.0; refZ=0.0;
        break;
    case 'j': // move ref point upwards along Y axis
        refY+=1.0;
        break;
    case 'n': // move ref point downwards along Y axis
        refY-=1.0;
        break;
    case 'b': // move ref point left along X axis
        refX-=1.0;
        break;
    case 'm': // move eye point right along X axis
        refX+=1.0;
        break;
    case 'k':  //move ref point away from screen/ along z axis
        refZ+=1;
        break;
    case 'l': //move ref point towards screen/ along z axis
        refZ-=1;
        break;

    case 27:    // Escape key
        exit(1);
    }

    glutPostRedisplay();
}

//Cube er point gulaaaa
static GLfloat v_cube[8][3] =
{
    //x, y, z co-ordinate
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0}, //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

//cube er 6 ta tolaaa ekta tolaa 4 ta bindu niyaa
static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};


//6 taa toler 6 ta color
static GLfloat colors[6][3] =
{
    {0.4, 0.1, 0.0}, //bottom
    {0.6, 0.0, 0.7}, //top
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.3, 0.6, 0.7}
};



void drawCube()
{

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        //Glut er vertex create kortesi..
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}


void Wall()
{
    // left wall
    glColor3f(1, 0.8, 0.7); //whole cube colour
    glPushMatrix(); //Buffer e code push koraa
    glTranslatef(-4.5, -1, 0); // shorano
    glScalef(1,  2,  5); //choto boro koraa. 1 no change, 2 means 2X
    drawCube(); //Cube aki disi
    glPopMatrix(); //Kaaj shesh then poped
    // right wall
    glColor3f(1, 0.8, 0.5);
    glPushMatrix();
    glTranslatef(-1.5, -1, .5);
    glScalef(5, 2, 0.1);
    drawCube();
    glPopMatrix();
   //ceiling
    glColor3f(1.0, 1, 1);
    glPushMatrix();
    //glScalef(5, 0.1, 7);
    glTranslatef(-2,5.1,0);
    glScalef(5, 0.1, 7);
    drawCube();
    glPopMatrix();
    // floor
    glColor3f(0.847, 0.54, 0.46);
    glPushMatrix();
    glTranslatef(-4, -1.5, -3);
    glScalef(5, 0.01, 5);
    drawCube();
    glPopMatrix();

    // carpet
    glColor3f(0.5, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(2.5, -1.3, 3);
    glScalef(2, 0.01, 2);
    drawCube();
    glPopMatrix();
}


void Clock()
{
        //Clock
        //clock body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(-0.9,1.8,7.87);
        //glRotatef(22, 0,0,1);
        glScalef(0.08, 0.25, 0.1);
        drawCube();
        glPopMatrix();

        //clock body white
        glColor3f(1.000, 0.894, 0.710);
        glPushMatrix();
        glTranslatef(-0.83,1.9,7.9);
        //glRotatef(22, 0,0,1);
        glScalef(0.06, 0.2, 0.08);
        drawCube();
        glPopMatrix();

        //clock hour handle
        glColor3f(0,0,0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(45, 1,0,0);
        glScalef(0.0001, 0.01, 0.04);
        drawCube();
        glPopMatrix();

       //clock minute handle
        glColor3f(0,0,0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(90, 1,0,0);
        glScalef(0.0001, 0.012, 0.08);
        drawCube();
        glPopMatrix();

        //clock body bottom strip
        glColor3f(0.2,0.1,0.1); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        //glRotatef(22, 0,0,1);
        glScalef(0.001, 0.01, 0.1);
        drawCube();
        glPopMatrix();

        //clock body right strip
        glColor3f(0.0,0.0,0.0); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        //glRotatef(22, 0,0,1);
        glScalef(0.005, 0.25, 0.01);
        drawCube();
        glPopMatrix();

        //clock body left strip
        glColor3f(0.2,0.1,0.1); //0.2,0.1,0.1
        glPushMatrix();
        glTranslatef(-0.65,1.8,8.2);
        //glRotatef(22, 0,0,1);
        glScalef(0.0001, 0.25, 0.01);
        drawCube();
        glPopMatrix();

}


void kitchen_Shelf() {
        glColor3f(0.8, 0.4, 0.4);
        glPushMatrix();
        glTranslatef(0.4, -1, .6);
        glScalef(1.5, 0.8, 0.5);
        drawCube();
        glPopMatrix();

        //Majkhaner divider
        glColor3f(0.7, 0.3, 0.41);
        glPushMatrix();
        glTranslatef(2.7, -1, 0.05);
        glScalef(0.05, 0.8, 0.7);
        drawCube();
        glPopMatrix();


        //Left Drawer
        glColor3f(0.7, 0.3, 0.41);
        glPushMatrix();
        glTranslatef(0.8, -0.5, 0.05);
        glScalef(0.5, 0.5, 0.7);
        drawCube();
        glPopMatrix();

        //Right Drawer
        glColor3f(0.7, 0.3, 0.41);
        glPushMatrix();
        glTranslatef(3.2, -0.5, 0.05);
        glScalef(0.5, 0.5, 0.7);
        drawCube();
        glPopMatrix();
}



void Fridge() {
        glColor3f(0.3, 0.1, 0);
        glPushMatrix();
        glTranslatef(5.5, -1, .6);
        glScalef(0.7, 1.5, 0.5);
        drawCube();
        glPopMatrix();

        //Border
        glColor3f(0.75, 0.75, 0.75);
        glPushMatrix();
        glTranslatef(5.5, 1.5, .6);
        glScalef(0.7, 0.03, 0.6);
        drawCube();
        glPopMatrix();

}
void stove() {
        glColor3f(0,0,0);
        glPushMatrix();
        glTranslatef(3.1, 1, .4);
        glScalef(0.4, 0.2, 0.5);
        drawCube();
        glPopMatrix();

        glColor3f(0,0,0);
        glPushMatrix();
        glTranslatef(1, 1, .4);
        glScalef(0.4, 0.2, 0.5);
        drawCube();
        glPopMatrix();
}
void TV(){
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-1, 1.4, 4.6); // -1 x er baame
    glScalef(0.0001, .65, .8);
    drawCube();
    glPopMatrix();

}

void TV_VITORE_KHELA() {
    glColor3f(0.5, 0.7, 1);
    glPushMatrix();
    glTranslatef(-1, 1.4, 6);
    glScalef(0.0004, 0.5, 0.5);
    drawCube();
    glPopMatrix();
}


void Table(){
    // main table
    glColor3f(0.97, 0.7, 0.41);
    glPushMatrix();
    glTranslatef(-1,-0.8,4);
    glScalef(0.5, 0.5,1.5);
    drawCube();
    glPopMatrix();

    //divider
    glColor3f(0.8, 0.67, 0.53);
    glPushMatrix();
    glTranslatef(-1.12, -0.8, 6);
    glScalef(0.55, 0.47, 0.05);
    drawCube();
    glPopMatrix();

    //Microwave
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(-1.2, 0.3, 6);
    glScalef(0.55, 0.47, -0.5);
    drawCube();
    glPopMatrix();

    //microwave side
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslatef(-1.12, 0.75, 6);
    glScalef(0.55, 0.3, 0.05);
    drawCube();
    glPopMatrix();

    //Table 2 Drawer Microwave
    glColor3f(0.8, 0.67, 0.53);
    glPushMatrix();
    glTranslatef(-1, -0.5, 8);
    glScalef(0.55, 0.3, -0.4);
    drawCube();
    glPopMatrix();

    //Table 2 Drawer 2 Microwave
    glColor3f(0.8, 0.67, 0.53);
    glPushMatrix();
    glTranslatef(-1, -0.5, 5.65);
    glScalef(0.55, 0.3, -0.4);
    drawCube();
    glPopMatrix();


}
void Picture(){
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(2.2, 2, 1.1);
    glScalef(.25, .7, -0.02);
    drawCube();
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(2.1,1.9,1);
    glScalef(.3, .8, -0.01);
    drawCube();
    glPopMatrix();
}


void Khawar_Table() {
    // Draw the base of the sofa
    glColor3f(0.7, 0.4, 0.1);  // Brown color
    glPushMatrix();
    glTranslatef(7, 0.7, 10);  // Position the sofa opposite of the table
    glRotatef(180, 0, 1, 0);     // Rotate the sofa to face the table
    glScalef(0.5, 0.05, 1.5);     // Adjust the size
    drawCube();
    glPopMatrix();


    glColor3f(0.6, 0.3, 0.1);  // Brown color
    glPushMatrix();
    glTranslatef(6.7, -0.8, 8.65);  // Position the sofa opposite of the table
    glRotatef(180, 0, 1, 0);     // Rotate the sofa to face the table
    glScalef(0.2, 0.5, 0.2);     // Adjust the size
    drawCube();
    glPopMatrix();
//    // Draw the backrest
//    glColor3f(0.7, 0.4, 0.1);  // Brown color
//    glPushMatrix();
//    glTranslatef(7,-0.2,11);  // Position the backrest
//    glRotatef(180, 0, 1, 0);     // Rotate the backrest to face the table
//    glScalef(0.1, 0.5, 1.5);     // Adjust the size
//    drawCube();
//    glPopMatrix();
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,1,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,  refX,refY,refZ,  0,1,0); //7,2,15, 0,0,0, 0,1,0

    glViewport(0, 0, 800, 600);

    Wall();
    //TV();
    //TV_VITORE_KHELA();
    Table();
    kitchen_Shelf();
    Fridge();
    stove();
    Picture();
    Khawar_Table();
    Clock();
    glFlush();
    glutSwapBuffers();
}


int main (int argc, char **argv)
{

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
 glutInitWindowSize(windowWidth, windowHeight);
 glutCreateWindow("C201094_Mehrab");
 glShadeModel( GL_SMOOTH );
 glEnable( GL_DEPTH_TEST );
 glutKeyboardFunc(myKeyboardFunc);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
