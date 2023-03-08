#Practica 2

Vamos a modificar dinamicamente elementos en pantalla (rotaciones, traslaciones y escala)
* Matriz modelo
* Matriz vista
* Matriz proyeccion

Esto se logra con gml, nos permite trabajar con matrices.

## Matrices de modelo, vista, y proyeccion
Necesitamos trabajar con las tres matrices MVP (Model, View, Proyection).
Proyeccion ortografica
* glm::ortho(xmin,xmax,ymin,ymax,zmin,zmax)
Proyeccion en perspectiva
* glm::perspective(FOV, Radio de aspecto,znear,zfar)
Radio de aspecto = ancho/alto (x/y)
Znear = se hace pegado al centro de proyeccion
