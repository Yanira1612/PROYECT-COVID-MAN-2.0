#include <allegro.h>
#include "Mapa.cpp"


int main()
{
    allegro_init();//inicia la librería Allegro
    install_keyboard();//nos permite utilizar las teclas
    install_mouse();//parametros del mouse
    set_color_depth(32);

    //Inicializacion de la instancia Nivel 1

    //const char filename[]="casita.bmp";
    //const char *filenamePtr=filename;
    int nivel=1;//Elegimos el nivel 1 del juego
    int ejeX=880;//Dimensiones de la ventana
    int ejeY=700;

    set_gfx_mode(GFX_AUTODETECT_WINDOWED,ejeX,ejeY,0,0);

    //codigo musica en allegro
 	if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

    //control para el sonido, izq y der
	set_volume(200, 200);

    Mapa noob(nivel,ejeX,ejeY);
    noob.setNivelMapa(2);
    noob.Mostrar();

    return 0;
}
END_OF_MAIN();
