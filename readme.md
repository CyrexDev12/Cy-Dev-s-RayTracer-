Notes: 

Compile Command 
mingw32-make

Clean Command: 
mingw32-make clean 


- Tuple: A point like (-4, 4, 3)
(x,y,z,w)
For a point in 3D space, you typically use w = 1 → (x, y, z, 1)
For a direction/vector, you use w = 0 → (x, y, z, 0)

W = 1 -> Point 
W = 0 -> Vector 



Matrix Implementation 
Using 2D vector dynamic arrays

Matrix Class includes:
vector<vector<double>>
rows
cols

and all of the needed operations 

Matrix Transformations 

Translation, Scaling, Rotation, Shearing can all be represented as matricies 


Identifying Hits 
- When rendering a scene we will need to identify which one of the intersections is actually visible from the ray's origin. 
(Some can be behind the ray, and others may be hidden or behind by other objects)
- We call the visible intersection the 'hit' 
(The hit will never be behind the ray's origin) (Since it is effectivley behind the camera), so we can ignore all intersections with negative t values. The hit will always be the intersection with the lowest nonnegative t value. 


Moving the sphere 
When we increase the distance between the sphere and the ray, we can translate the ray away from the sphere, and it is indifferent from
translating the sphere away from the ray. 

Scaling 
- If we want to make our sphere bigger it is just the same as shrinking the distance between the ray and the sphere. 
- It is an inverse relationship. 
- We scale the ray by the inverse of how you were wanting to scale the sphere. 

Rotation 
- If we want to rotate the sphere, you rotate the sphere by the inverse of the rotation you wanted to apply to the sphere. 

To sum up transformations, whatever transformation we want to apply to the sphere, we apply the inverse to the ray. 


Lighting and Shading 

- We implement a model to simulate the reflection of light from a surface, which allows us to draw the sphere and make it look '3D' 

HOW TO: 
- Implement a source of light 
- Implement a shading algorithm to approximate how birhgtly that light illuminates the surfaces it shines on 

(Most ray tracers favor approximations over physically accurate simulations)

We define 4 different vectors 
If p is where your ray intersects an object, these four vectors are defined as: 
- E is the eye vector, pointing from p to the origin of the ray.
- L is the light vector, poiting from p to the position of the light source.
- N is the surface normal, a vector that is perpendicular to the surface at P. 
- R is the reflection vector, poiting in the direction that incoming light would bounce, or reflect. 

Phong Reflection Model 
Simulates interaction between three different types of lighting. 

- Ambient Reflection: Background lighting. Or light reflected from other objects in its environment. The Phong model treats this as a constant coloring all points on the surface equally. 
- Diffuse Reflection: Light reflected from a matte surface. It depends only on the angle between the light source and the surface normal. 
- Specular Reflection: Reflection of the light source itself and results in what is called a specular highlight. The bright spot on a curved surface. It depends only on the angle between the reflection vector and the eye vector and is controlled by a parameter that we cann shininess. The higher the shininess the smaller and tighter the specular highlight. 


The lighting Function (Located within the object class, e.g. sphere)
Expects 5 arguments material, point being illuminated, the light source, eye and normal vectors from the phong reflection model. 