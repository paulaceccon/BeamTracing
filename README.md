# BeamTracing
A *basic* 2D version of the [Beam Tracing](https://en.wikipedia.org/wiki/Beam_tracing) algorithm presented in:

[Thomas Funkhouser, Ingrid Carlbom, Gary Elko, Gopal Pingali, Mohan Sondhi, and Jim West. 1998. A beam tracing approach to acoustic modeling for interactive virtual environments. In *Proceedings of the 25th annual conference on Computer graphics and interactive techniques* (SIGGRAPH '98). ACM, New York, NY, USA, 21-32. DOI=http://dx.doi.org/10.1145/280814.280818](http://www.cs.princeton.edu/~funk/sig98.pdf)

## Screeshots
The environment is represented as a set of lines. Red lines represent walls and green lines represent doors. For each test case the ray emanate from the same source (represented as a white dot) and the listener is somewhere inside the room **R**. The maximum number of reflection/transmission allowed is showed in the upper left part of each image. 

###### 2 Degrees of Transmission/Reflection
<img src="https://github.com/paulaceccon/BeamTracing/blob/master/Results/d2to2.png" alt="alt text" width="500">

###### 3 Degrees of Transmission/Reflection
<img src="https://github.com/paulaceccon/BeamTracing/blob/master/Results/d3to2.png" alt="alt text" width="500">

###### 4 Degrees of Transmission/Reflection
<img src="https://github.com/paulaceccon/BeamTracing/blob/master/Results/d4to0.png" alt="alt text" width="500">
