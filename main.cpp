/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pceccon
 *
 * Created on October 14, 2015, 11:38 AM
 */

#include "Environment.h"
#include "Wall.h"
#include "Room.h"
#include "Core.h"

#include <cstdlib>
#include <cmath>

#ifdef __APPLE__
        #include <OpenGL/gl.h>
        #include <GLUT/glut.h>
#elif __WINDOWS__
        #include <GL/gl.h>
        #include <GL/glut.h>
#endif

using namespace std;



/// Data Input ///

Environment env;

void buildEnvironment()
{
    /*
    *----*----*--------*
    |    |    |        |
    |  A .    |   D    |
    |    |    |        |
    *----*  C |        |
    |    |    *---   --*
|  B .   .             |
    |    |    .   E    |
    *----*-------------*
    */
    
    // Points
    env.addPoint(core::Pointf(0, 0));     // 0
    env.addPoint(core::Pointf(0, 10));    // 1
    env.addPoint(core::Pointf(10, 10));   // 2
    env.addPoint(core::Pointf(10, 0));    // 3
    env.addPoint(core::Pointf(5, 0));     // 4
    env.addPoint(core::Pointf(10, -10));  // 5
    env.addPoint(core::Pointf(0, -10));   // 6
    env.addPoint(core::Pointf(-5, -10));  // 7
    env.addPoint(core::Pointf(-5, -7));   // 8
    env.addPoint(core::Pointf(-10, -10)); // 9
    env.addPoint(core::Pointf(-10, 0));   // 10
    env.addPoint(core::Pointf(-5, 0));    // 11
    env.addPoint(core::Pointf(-5, -3));   // 12
    env.addPoint(core::Pointf(-5, 3));    // 13
    env.addPoint(core::Pointf(-10, 10));  // 14
    env.addPoint(core::Pointf(-5, 10));   // 15
    env.addPoint(core::Pointf(-5, 7));    // 16
    env.addPoint(core::Pointf(3, 0));     // 17
    
    // Walls
    env.addWall(Wall (14, 10, 0.0));       // 0
    env.addWall(Wall (15, 14, 0.0));       // 1
    env.addWall(Wall (1, 15, 0.0));        // 2
    env.addWall(Wall (2, 1, 0.0));         // 3
    env.addWall(Wall (3, 2, 0.0));         // 4
    env.addWall(Wall (5, 3, 0.0));         // 5
    env.addWall(Wall (6, 5, 0.0));         // 6
    env.addWall(Wall (7, 6, 0.0));         // 7
    env.addWall(Wall (9, 7, 0.0));         // 8
    env.addWall(Wall (10, 9, 0.0));        // 9
    env.addWall(Wall (10, 11, 0.0));       // 10 
    env.addWall(Wall (15, 16, 0.0));       // 11
    env.addWall(Wall (13, 11, 0.0));       // 12
    env.addWall(Wall (12, 13, 0.0));       // 13
    env.addWall(Wall (8, 7, 0.0));         // 14
    env.addWall(Wall (0, 1, 0.0));         // 15
    env.addWall(Wall (17, 0, 0.0));        // 16
    env.addWall(Wall (3, 4, 0.0));         // 17
    env.addWall(Wall (8, 12, -INFINITY));  // 18
    env.addWall(Wall (0, 6, -INFINITY));   // 19
    env.addWall(Wall (17, 4, -INFINITY));  // 20
    env.addWall(Wall (16, 13, -INFINITY)); // 21
    
    // Rooms
    Room rA, rB, rC, rD, rE;
    
    // Room A
    rA.addWallIdx(0);
    rA.addWallIdx(1);
    rA.addWallIdx(11);
    rA.addWallIdx(21);
    rA.addWallIdx(12);
    rA.addWallIdx(10);
    
    env.addRoom(rA);
    
    // Room B
    rB.addWallIdx(8);
    rB.addWallIdx(14);
    rB.addWallIdx(18);
    rB.addWallIdx(13);
    rB.addWallIdx(10);
    rB.addWallIdx(9);
    
    env.addRoom(rB);

    // Room C
    rC.addWallIdx(2);
    rC.addWallIdx(11);
    rC.addWallIdx(21);
    rC.addWallIdx(12);
    rC.addWallIdx(13);
    rC.addWallIdx(18);
    rC.addWallIdx(14);
    rC.addWallIdx(7);
    rC.addWallIdx(19);
    rC.addWallIdx(15);
    
    env.addRoom(rC);

    // Room D
    rD.addWallIdx(3);
    rD.addWallIdx(15);
    rD.addWallIdx(16);
    rD.addWallIdx(20);
    rD.addWallIdx(17);
    rD.addWallIdx(4);
    
    env.addRoom(rD);
    
    // Room D
    rE.addWallIdx(17);
    rE.addWallIdx(20);
    rE.addWallIdx(16);
    rE.addWallIdx(19);
    rE.addWallIdx(6);
    rE.addWallIdx(5);
    
    env.addRoom(rE);
    
    std::vector<std::vector<Environment::Node> > adj;
    adj.resize(env.getRooms().size());
    env.buildAdjacencyGraph(adj);
}



/// OpenGL ///

// Defines the coordinate system:  (-winW, winW) - X and (-winH, winH) - Y. 
double winW = 25.0, winH = 25.0;

// Grid size. 
const double lenghGrid = 24.0;

// Window size in pixels.
int widthWin = 600, heightWin = 600;

// Background. 1.0f for black / 0.0f for white.
float colorGrid = 1.0f;

/**
 * Render the environment.
 */
void renderEnvironment()
{   
    glBegin( GL_LINES );
    
    std::vector<core::Pointf> points = env.getPoints();
    std::vector<Wall> walls = env.getWalls();
    for (unsigned int i = 0; i < walls.size(); i++)
    {
        Wall wall = walls.at(i);
        int startPointIdx = wall.getStartPoingID();
        int endPointIdx = wall.getEndPoinID();
        float specFactor = wall.getSpecularValue();

        if (specFactor != -INFINITY)
            glColor3f( 1.0, 0.0, 0.0 );
        else
            glColor3f( 0.0, 1.0, 0.0 );

        glVertex2f( points.at(startPointIdx).x, points.at(startPointIdx).y );
        glVertex2f( points.at(endPointIdx).x, points.at(endPointIdx).y );
    }
    
    glEnd( );
}

/**
 * Render the grid.
 */
void renderGrid( void )
{
    double i = 0.0, j = 0.0;

    // Draws small squares.
    for (i = -winH; i < winH; i++)
    {
        for (j = -winW; j < winW; j++)
        {
            glBegin( GL_POLYGON );
            glColor3f( fabs( colorGrid - 0.94f ), fabs( colorGrid - 0.94f ), fabs( colorGrid - 0.94f ) );
            glVertex2f( i * 2, j * 2 );
            glVertex2f( i * 2 + 1, j * 2 );
            glVertex2f( i * 2 + 1, j * 2 + 1 );
            glVertex2f( i * 2, j * 2 + 1 );
            glEnd( );
        }
    }

    // Draws grid lines.
    glBegin( GL_LINES );

    glColor3f( fabs( colorGrid - 0.9f ), fabs( colorGrid - 0.9f ), fabs( colorGrid - 0.9f ) );
    for (i = -winW; i < winW; i++)
    {
        glVertex2f( i, -winH );
        glVertex2f( i, winH );
    }
    for (i = -winH; i < winH; i++)
    {
        glVertex2f( -winW, i );
        glVertex2f( winW, i );
    }

    // X and Y axes.
    glColor3f( fabs( colorGrid - 0.4f ), fabs( colorGrid - 0.4f ), fabs( colorGrid - 0.4f ) );
    glVertex2f( 0.0, -winH );
    glVertex2f( 0.0, winH );
    glVertex2f( -winW, 0.0 );
    glVertex2f( winW, 0.0 );
    glEnd( );
}


/**
 * Deals with screen events. Must be called every time the screen is redraw.
 */
void display( void )
{
    glClearColor( fabs( colorGrid - 1.0 ), fabs( colorGrid - 1.0 ), fabs( colorGrid - 1.0 ), 1.0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    renderGrid( );

    glPushMatrix( );
    {    
        renderEnvironment();
    }
    glPopMatrix( );

    glutSwapBuffers( );
}


/**
 * Called when the screen is resized.
 * 
 * @param width Screen width
 * @param height Screen height
 */
void reshape( int width, int height )
{
    glViewport( 0, 0, width, height );

    widthWin = width;
    heightWin = height;

    winW = (int) (width / lenghGrid + 0.5);
    winH = (int) (height / lenghGrid + 0.5);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    gluOrtho2D( -winW, winW, -winH, winH );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}



/// Main ///

int main(int argc, char** argv) 
{
    buildEnvironment();
    
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize( 600, 600 );
    glutInitWindowPosition( 0, 0 );
    glutCreateWindow( "2D Beam Tracing" );
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutMainLoop( );

    return 0;
}

