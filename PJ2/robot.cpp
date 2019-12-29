//
//  car.cpp
//  Graphics_landscape
//
//  Created by yyx on 2019/12/16.
//  Copyright © 2019 yyx. All rights reserved.
//

#include <stdio.h>
//#include <windows.h>
#include <GLUT/GLUT.h>
#include <math.h>
static float theta = 0;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static float ratio;
static float x=0.0f,y=1.75f,z=5.0f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
void changeSize(int w, int h)
{
    
    // 防止被0除.
    if(h == 0)
        h = 1;
    
    ratio = 1.0f * w / h;
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //设置视口为整个窗口大小
    glViewport(0, 0, w, h);
    
    //设置可视空间
    gluPerspective(120.0f, ratio, 1.0f, 1500.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx,y + ly,z + lz,
              0.0f,1.0f,0.0f);
}

void robot()//绘制机器人
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1, 0, 0);
    glScalef(4, 4, 0.5);
    glutSolidCube(1);//绘制立方体身
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(0, 2.5, 0);
    glScalef(1, 1, 0.5);
    glutSolidCube(1);//绘制立方体头
    glPopMatrix();
    
    glPushMatrix();
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(theta, 1, 0, 0);
    glTranslatef(0, -2, 0);
    glColor3f(1, 0.5, 0.2);
    glTranslatef(-2.5, 1.25, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//绘制立方体右手
    glPopMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(theta, 1, 0, 0);
    glTranslatef(0, -2, 0);//大臂
    glTranslatef(0, 0.5, 0);
    glRotatef(theta, 1, 0, 0);
    glTranslatef(0, -0.5, 0);
    glColor3f(1, 0.5, 0.2);
    glTranslatef(-2.5, 0.25, 0.5);
    glRotatef(-60, 1, 0, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//小臂
    glPopMatrix();
    
    glPushMatrix();
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(-1 * theta, 1, 0, 0);
    glTranslatef(0, -2, 0);
    glColor3f(1, 0.5, 0.2);
    glTranslatef(2.5, 1.25, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//绘制立方体左手
    glPopMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(theta*-1, 1, 0, 0);
    glTranslatef(0, -2, 0);//大臂
    glTranslatef(0, 0.5, 0);
    glRotatef(theta*-1, 1, 0, 0);
    glTranslatef(0, -0.5, 0);
    glColor3f(1, 0.5, 0.2);
    glTranslatef(2.5, 0.25, 0.5);
    glRotatef(-60, 1, 0, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//小臂
    glPopMatrix();
    
    glPushMatrix();
    glPushMatrix();
    glTranslatef(-3.5, -4, 0);
    glTranslatef(0, 2, 0);
    glRotatef(-1 * theta, 1, 0, 0);
    glTranslatef(0, -2, 0);
    glColor3f(0.5, 0.5, 1);
    glTranslatef(2.5, 1.25, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//绘制立方体右腿
    glPopMatrix();
    glTranslatef(-3.5, -4, 0);
    glTranslatef(0, 2, 0);
    glRotatef(-1 * theta, 1, 0, 0);
    glTranslatef(0, -2, 0);//大腿
    glTranslatef(0, 0.5, 0);
    glRotatef(-1 * theta*0.4, 1, 0, 0);
    glTranslatef(0, -0.5, 0);
    glColor3f(0.5, 0.5, 1);
    glTranslatef(2.5, 0.25, -0.5);
    glRotatef(60, 1, 0, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//小腿
    glPopMatrix();
    
    glPushMatrix();
    glPushMatrix();
    glTranslatef(-1.5, -4, 0);
    glTranslatef(0, 2, 0);
    glRotatef(theta, 1, 0, 0);
    glTranslatef(0, -2, 0);
    glColor3f(0.5, 0.5, 1);
    glTranslatef(2.5, 1.25, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//绘制立方体左腿
    glPopMatrix();
    glTranslatef(-1.5, -4, 0);
    glTranslatef(0, 2, 0);
    glRotatef(theta, 1, 0, 0);
    glTranslatef(0, -2, 0);//大腿
    glTranslatef(0, 0.5, 0);
    glRotatef(theta*0.4, 1, 0, 0);
    glTranslatef(0, -0.5, 0);
    glColor3f(0.5, 0.5, 1);
    glTranslatef(2.5, 0.25, -0.5);
    glRotatef(60, 1, 0, 0);
    glScalef(1, 1.5, 0.5);
    glutSolidCube(1);//小腿
    glPopMatrix();
    glutSwapBuffers();
}

//定义键盘控制函数
void SpecialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)      xRot -= 5.0f;
    if (key == GLUT_KEY_DOWN)    xRot += 5.0f;
    if (key == GLUT_KEY_LEFT)    yRot -= 5.0f;
    if (key == GLUT_KEY_RIGHT)   yRot += 5.0f;
    glutPostRedisplay(); // 刷新窗口
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//对GLUT进行初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//初始化显示模式
    glutCreateWindow("车");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//最初的背景色
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);//平滑模式填充线段
    glMatrixMode(GL_PROJECTION);//投影矩阵
    glLoadIdentity();//变换前将矩阵设置为单位矩阵
    glOrtho(-100, 100, -100, 100, -100, 100);//平行投影
    glutSpecialFunc(SpecialKeys);  //注册功能键回调函数
    glutDisplayFunc(robot);
    glutReshapeFunc(changeSize);
    glutMainLoop();
    return 0;
}
