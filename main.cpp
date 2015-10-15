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
    
    // Rooms
    Room a, b, c, d, e;
    
    // Room A
    Wall a1 (core::Linef(core::Pointf(-10, 0),  core::Pointf(-10, 10)), 0.0);
    Wall a2 (core::Linef(core::Pointf(-10, 10), core::Pointf(-5, 10)),  0.0);
    Wall a3 (core::Linef(core::Pointf(-5, 10),  core::Pointf(-5, 7)),   0.0);
    Wall a4 (core::Linef(core::Pointf(-5, 3),   core::Pointf(-5, 0)),   0.0);
    Wall a5 (core::Linef(core::Pointf(-5, 0),   core::Pointf(-10, 0)),  0.0);
    
    a.addWall(a1);
    a.addWall(a2);
    a.addWall(a3);
    a.addWall(a4);
    a.addWall(a5);
    
    env.addRoom(a);
    
    // Room B
    Wall b1 (core::Linef(core::Pointf(-10, 0),   core::Pointf(-5, 0)),    0.0);
    Wall b2 (core::Linef(core::Pointf(-5, 0),    core::Pointf(-5, -3)),   0.0);
    Wall b3 (core::Linef(core::Pointf(-5, -7),   core::Pointf(-5, -10)),  0.0);
    Wall b4 (core::Linef(core::Pointf(-5, -10),  core::Pointf(-10, -10)), 0.0);
    Wall b5 (core::Linef(core::Pointf(-10, -10), core::Pointf(-10, 0)),   0.0);
    
    b.addWall(b1);
    b.addWall(b2);
    b.addWall(b3);
    b.addWall(b4);
    b.addWall(b5);
    
    env.addRoom(b);
    
    // Room C
    Wall c1 (core::Linef(core::Pointf(-5, 7),   core::Pointf(-5, 10)),  0.0);
    Wall c2 (core::Linef(core::Pointf(-5, 10),  core::Pointf(0, 10)),   0.0);
    Wall c3 (core::Linef(core::Pointf(0, 10),   core::Pointf(0, 0)),    0.0);
    Wall c4 (core::Linef(core::Pointf(0, -10),  core::Pointf(-5, -10)), 0.0);
    Wall c5 (core::Linef(core::Pointf(-5, -10), core::Pointf(-5, -7)),  0.0);
    Wall c6 (core::Linef(core::Pointf(-5, -3),  core::Pointf(-5, 0)),   0.0);
    Wall c7 (core::Linef(core::Pointf(-5, 0),   core::Pointf(-5, 3)),   0.0);
    
    c.addWall(c1);
    c.addWall(c2);
    c.addWall(c3);
    c.addWall(c4);
    c.addWall(c5);
    c.addWall(c6);
    c.addWall(c7);
    
    env.addRoom(c);    
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
    buildEnvironment();
    
    glColor3f( 1.0, 0.0, 0.0 );
    glBegin( GL_LINES );
    
    std::vector<Room> rooms = env.getRooms();
    for (unsigned int i = 0; i < rooms.size(); i++)
    {
        Room room = rooms.at(i);
        std::vector<Wall> walls = room.getWalls();
        
        for (unsigned int j = 0; j < walls.size(); j++)
        {
            Wall wall = walls.at(j);
            
            glVertex2f( wall.getLine().startPoint.x, wall.getLine().startPoint.y );
            glVertex2f( wall.getLine().endPoint.x, wall.getLine().endPoint.y );
        }
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

