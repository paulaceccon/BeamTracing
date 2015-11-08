/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ray.h
 * Author: pceccon
 *
 * Created on October 22, 2015, 10:05 AM
 */

#ifndef RAY_H
#define RAY_H

#include "Core.h"

class Ray 
{
    public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         */
        Ray();
        
        /**
         * Instantiates a ray with a specific origin and direction.
         * 
         * @param origin    The ray origin.
         * @param direction The ray direction.
         */
        Ray(core::Pointf& o, core::Vectorf& d);
        
        /**
         * Copy constructor.
         */
        Ray(const Ray& r);
        
        /**
         * Destructor.
         */
        virtual ~Ray();
        
        
        
        /// Methods ///
        
        /**
         * Gets the ray's origin.
         * 
         * @return @_origin.
         */
        const core::Pointf getOrigin() const;
        
        /**
         * Gets the ray's direction.
         * 
         * @return @_direction. 
         */
        const core::Vectorf getDirection() const;
        
    private:
        
        core::Pointf  _origin;
        core::Vectorf _direction;
};

#endif /* RAY_H */

