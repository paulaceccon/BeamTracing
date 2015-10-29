/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Environment.h
 * Author: pceccon
 *
 * Created on October 15, 2015, 1:02 PM
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Room.h"
#include "Wall.h"
#include "Core.h"
#include "Source.h"
#include "TreeNode.h"
#include "Tree.h"

#include <vector>
#include <list>

class Environment 
{
    public:
        
        typedef struct GraphNode
        {
            int roomIdx;
            int wallIdx;
        } GraphNode;
        
        /// Constructors ///
        
        /**
         * Default constructor.
         */
        Environment();
        
        /**
         * Instantiates an environment with a set of rooms.
         * 
         * @param r A set of rooms that defines an environment.
         */
        Environment(const std::vector<Room> r);
        
        /**
         * Copy constructor.
         */
        Environment(const Environment& e);
        
        /**
         * Destructor.
         */
        virtual ~Environment();
        
        
        
        /// Methods ///
        
        /**
         * Gets the set of rooms that define an environment.
         * 
         * @return @_rooms.
         */
        const std::vector<Room>& getRooms() const;
        
        /**
         * Adds a room to @this environment.
         * 
         * @param r The room to be added to @this.
         */
        void addRoom(const Room& r);
   
        /**
        * Gets the set of walls that defines an environment.
        * 
        * @return @_walls.
        */
        const std::vector<Wall>& getWalls() const;
        
        /**
         * Adds a wall to @this environment.
         * 
         * @param w The wall to be added to @this.
         */
        void addWall(const Wall& w);
         
        /**
         * Adds a point to @this environment.
         * 
         * @param p The point to be added to @this.
         */
        void addPoint(const core::Pointf& p);
        
        /**
         * Gets the set of points that defines the environment.
         * 
         * @return @_points
         */
        const std::vector<core::Pointf>& getPoints() const;
        
        /**
         * Sets the source position.
         * 
         * @param s The source position.
         */
        void setSource(const Source& s);
        
        /**
         * Gets the beam tree.
         * 
         * @return @tree.
         */
        Tree& getBeamTree();
        
        /**
         * Builds an adjacency graph in which each node is a room id and each edge
         * is a wall id.
         * 
         * @param adj A reference to the adjacency graph to be written.
         */
        void buildAdjacencyGraph(std::vector<std::vector<GraphNode> >& adj);
        
        /**
         * Performs a depth-first search in a graph.
         * 
         * @param adj The graph structure.
         * @param v   The node in which to start the search.
         */
        void DFS(const std::vector<std::vector<GraphNode> >& adj, int v);
 
    private:
        
        std::vector<Room> _rooms;
        
        std::vector<Wall> _walls;
        
        std::vector<core::Pointf> _points;
        
        Source _source;
        
        Tree _beamTree;
        
        
        
        /// Methods ///
        
        /**
         * Builds an array representing, for each wall, in which rooms 
         * it is present. 
         * 
         * @param adj An array of the size of the number of @_walls, in which
         * each position contains the rooms in which a specific wall is present.
         */
        void buildEdgesInRooms(std::vector<std::vector<int> >& adj);
        
        /**
         * Traverses the graph in depth-first search.
         * 
         * @param adj Adjacency graph to be traversed.
         * @param v   Starting vertex.
         * @param t   Contains information about the last visited edge.
         * @param max Maximum depth to be visited.
         */
        void traverse(const std::vector<std::vector<GraphNode> >& adj, int v, TreeNode& t, int max);
        
        /**
         * Performs the sound propagation (transmission and reflection).
         * 
         * @param t  A reference to the information of the previous sound propagation performed.
         * @param n  A reference to the current visited node.
         * @param i1 The first point of intersection between the current wall and the beam.
         * @param i2 The second point of intersection between the current wall and the beam.
         */
        void soundPropagation(TreeNode& t, const GraphNode& n, core::Pointf& i1, core::Pointf& i2);
        
        /**
         * Detects if an edge intersects the current beam.
         * 
         * @param t    The current tree node, containing information about the previous sound propagation.
         * @param pa   The first point that defines a line of the beam.
         * @param pb   The second point that defines a line of the beam.
         * @param outA A reference to the first point of intersection to be written, if it exists.
         * @param outB A reference to the second point of intersection to be written, if it exists.
         * @return     True, if the edge intersects the beam. False, otherwise.
         */
        bool intersectBeam(const TreeNode& t, const core::Pointf& pa, const core::Pointf& pb, core::Pointf& outA, core::Pointf& outB);
        
        /**
         * Gets the point that define an edge, properly oriented.
         * 
         * @param wId The wall id.
         * @param rId The room id.
         * @param sP  A reference to the first point to be written.
         * @param eP  A reference to the second point to be written.
         */
        void getOrientedWallPoints(const int wId, const int rId, core::Pointf& sP, core::Pointf& eP);
};

#endif /* ENVIRONMENT_H */

