## Datos
* X,Y,Z
* R G B a
* Normales
* Tangentes
* UV (Texturas)
## Primitivas Basicas
* Puntos
* Aristas
* Triangulos
## Transformaciones
* Translacion
* Rotacion
* Escalamiento

## VBO y VBA
Alojamos posiciones, colores, tangentes, coordenadas de textura, etc.
Con el VAO podemos guardar varios VBOs.
No puede haber vertex shaders sin fragment shaders.
Atrib pointer nos ayuda para navegar en la posicion activa y contigua.

## EBO (Element Buffer Object)
Almacena VAO. Aqui si podemos saltar en la informacion.

## Formas de dibujo
* GL_POINTS: Vertices separados
* GL_LINES: Cada par de vertices definen
* GL_TRIANGLES: Cada triplete de vertices definen un triangulo.
* GL_LINE_STRIP: Lineas conectadas
* GL_LINE_LOOP: lineas conectadas, con union del 1er y ultimo
### Vertice
* GL_TRIANGLES
* GL_TRIANGLES_FAN: Este va de derecha izquierda.

Hay una imagen en la presentacion que describe cada uno de ellos

# Referencias
* https://doc.instantreality.org/tools/color_calculator/
