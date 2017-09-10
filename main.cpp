#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
    color_t color1 = {255, 0, 0, 255};
    color_t color2 = {0, 255, 0, 255};
    color_t color3 = {0, 0, 255, 255};
    pixel_t p1 = {256, 26, color1};
    pixel_t p2 = {128, 242, color2};
    pixel_t p3 = {383, 242, color3};
    pixel_t p4 = {128, 242, color1};
    pixel_t p5 = {0, 460, color2};
    pixel_t p6 = {255, 460, color3};
    pixel_t p7 = {383, 242, color1};
    pixel_t p8 = {255, 460, color2};
    pixel_t p9 = {512, 460, color3};

    //*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

    // demonstracao da drawLine()
    /* drawLine({0, 0, color1}, {512, 512, color1}); */
    /* drawLine({256, 0, color1}, {256, 512, color1}); */
    /* drawLine({512, 0, color1}, {0, 512, color1}); */
    /* drawLine({512, 256, color1}, {0, 256, color1}); */

    // demonstracao da drawTriangle()
    drawTriangle(p1, p2, p3);
    drawTriangle(p4, p5, p6);
    drawTriangle(p7, p8, p9);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

