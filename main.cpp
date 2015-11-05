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
#include "Source.h"
#include "TreeNode.h"
#include "Point.h"
#include "MathUtils.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

#ifdef __APPLE__
        #include <OpenGL/gl.h>
        #include <GLUT/glut.h>
#elif __WINDOWS__
        #include <GL/gl.h>
        #include <GL/glut.h>
#endif



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
    env.addWall(Wall (11, 12, 0.0));       // 13
    env.addWall(Wall (8, 7, 0.0));         // 14
    env.addWall(Wall (0, 1, 0.0));         // 15
    env.addWall(Wall (17, 0, 0.0));        // 16
    env.addWall(Wall (3, 4, 0.0));         // 17
    env.addWall(Wall (8, 12, INFINITY));  // 18
    env.addWall(Wall (0, 6, INFINITY));   // 19
    env.addWall(Wall (17, 4, INFINITY));  // 20
    env.addWall(Wall (16, 13, INFINITY)); // 21
    
    // Rooms
    Room rA, rB, rC, rD, rE;
    rA.setIdx(0);
    rB.setIdx(1);
    rC.setIdx(2);
    rD.setIdx(3);
    rE.setIdx(4);
    
    // Room A
    rA.addWall(0,   1);
    rA.addWall(1,   1);
    rA.addWall(11, -1);
    rA.addWall(21, -1);
    rA.addWall(12, -1);
    rA.addWall(10,  1);
    
    env.addRoom(rA);
    
    // Room B
    rB.addWall(8,   1);
    rB.addWall(14, -1);
    rB.addWall(18,  1);
    rB.addWall(13, -1);
    rB.addWall(10, -1);
    rB.addWall(9,   1);
    
    env.addRoom(rB);

    // Room C
    rC.addWall(2,   1);
    rC.addWall(11,  1);
    rC.addWall(21,  1);
    rC.addWall(12,  1);
    rC.addWall(13,  1);
    rC.addWall(18, -1);
    rC.addWall(14,  1);
    rC.addWall(7,   1);
    rC.addWall(19, -1);
    rC.addWall(15,  1);
    
    env.addRoom(rC);

    // Room D
    rD.addWall(3,   1);
    rD.addWall(20,  1);
    rD.addWall(16, -1);
    rD.addWall(15, -1);
    rD.addWall(17, -1);
    rD.addWall(4,   1);
    
    env.addRoom(rD);
    
    // Room E
    rE.addWall(17, 1);
    rE.addWall(20, -1);
    rE.addWall(16,  1);
    rE.addWall(19,  1);
    rE.addWall(6,   1);
    rE.addWall(5,   1);
    
    env.addRoom(rE);
    
    Source src(rD, core::Pointf(5, 5));
    env.setSource(src);
    
    std::vector<std::vector<Environment::GraphNode> > adj;
    adj.resize(env.getRooms().size());
    env.buildAdjacencyGraph(adj);
    
    env.DFS(adj, src.getInsideRoom().getRoomIdx());
    
    env.getValidPaths(4);
}



/// OpenGL ///

// Defines the coordinate system:  (-winW, winW) - X and (-winH, winH) - Y. 
double winW = 25.0, winH = 25.0;

// Grid size. 
const double lenghGrid = 50.0;

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
        int endPointIdx = wall.getEndPointID();
        float specFactor = wall.getSpecularValue();

        if (specFactor != INFINITY)
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
 * Renders the beam tree, showing all paths.
 * 
 * @param root The beam tree root.
 * @param p1   The end point of the first ray.
 * @param p2   The end point of the second ray.
 */
void renderTree( TreeNode& root, int depth )
{
//    glColor3f( 1, 1, 0 );
//    glPointSize( 6 );
//    
//    if ( listenerInRoom == root.getInsideRoom() )
//        return true;
//    std::vector<TreeNode> c = root.getChildren( );
//    for( unsigned int i = 0; i < c.size(); i++ )
//        bool found = renderTree( c[i], depth+1 );

//    glEnable( GL_POINT_SMOOTH );
//    glEnable( GL_BLEND );
//    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
//    glBegin( GL_POINTS );
//    glVertex2f( root.getSourcePosition().x, root.getSourcePosition().y );
//    glEnd( );
//    
//    if ( root.getChildren().size() > 0)
//    {
//        if ( depth == 0 )
//        {
//            glBegin( GL_LINES );
//            glVertex2f( root.getSourcePosition().x, root.getSourcePosition().y );
//            glVertex2f( root.getPoint(1).x, root.getPoint(1).y );
//
//            glVertex2f( root.getSourcePosition().x, root.getSourcePosition().y );
//            glVertex2f( root.getPoint(2).x, root.getPoint(2).y );
//            glEnd( );
//        }
//        else
//        {
//            core::Pointf i1;
//            core::Pointf i2;
//
//            core::Pointf p1 = root.getChild(0).getPoint(1);
//            core::Pointf p2 = root.getChild(0).getPoint(2);
//            MathUtils::pointOfIntersection(root.getSourcePosition(), root.getPoint(1), p1, root.getPoint(2), i1);
//            MathUtils::pointOfIntersection(root.getSourcePosition(), root.getPoint(1), p2, root.getPoint(2),  i2);
//
//            glBegin( GL_LINES );
//            glVertex2f( i1.x, i1.y );
//            glVertex2f( p1.x, p1.y );
//
//            glVertex2f( i2.x, i2.y );
//            glVertex2f( p2.x, p2.y );
//            glEnd( );
//        }
//    }
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
        renderEnvironment( );
        renderTree( env.getBeamTree().root, 0);
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

