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
#include "Point.h"
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
        
        void setSource(const Source& s);
        
        void buildAdjacencyGraph(std::vector<std::vector<GraphNode> >& adj);
        
        void DFS(const std::vector<std::vector<GraphNode> >& adj, int v);
        
        void traverse(const std::vector<std::vector<GraphNode> >& adj, int v, TreeNode& t, int max);
        
        void auralization(TreeNode& t, const GraphNode& n);
        
        const Tree& getBeamTree() const;
        
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
};

#endif /* ENVIRONMENT_H */

