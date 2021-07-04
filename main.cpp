#include <allegro.h>
#include "Mapa.h"


int main()
{
    allegro_init();//inicia la librería Allegro
    install_keyboard();//nos permite utilizar las teclas

    set_color_depth(32);

    //Inicializacion de la instancia Nivel 1

    //const char filename[]="casita.bmp";
    //const char *filenamePtr=filename;
    int nivel=1;//Elegimos el nivel 1 del juego
    int ejeX=880;//Dimensiones de la ventana
    int ejeY=700;

    set_gfx_mode(GFX_AUTODETECT_WINDOWED,ejeX,ejeY,0,0);

    Mapa noob(nivel,ejeX,ejeY);
    //noob.setNivelMapa(1);
    noob.Mostrar();

    return 0;
}
END_OF_MAIN();


/*
#include <iostream>
#include <allegro.h>

using namespace std;

#define MAXFILAS 20 //Para el eje y (19)
#define MAXCOLS  31 //Parael eje x (30)
BITMAP *pacbmp;
BITMAP *pacman;
BITMAP *comida;
int dir=4;
int px=30*14,py=30*17;

char mapa[MAXFILAS][MAXCOLS]={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X     o  o  XXXXX           X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X                           X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XXXXXX XXX XXXXXXoXXX X",
  "X XXX XX             XX XXX X",
  "      XX XXXXXXXXXXX XX      ",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX XX             XX XXX X",
  "X XXX XXXXXX XXX XXXXXX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX                   XXX X",
  "X XXX XXXX XXXXXXXX XXX XXX X",
  "X XXX XXXX          XXX XXX X",
  "X          XXXXXXXX         X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
void dibujar_mapa(BITMAP*,BITMAP *);
void pantalla(BITMAP*);
void dibujar_personaje(BITMAP*);
bool game_over();
int main()
{
    allegro_init();//inicia la librería Allegro
    install_keyboard();//nos permite utilizar las teclas

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,880,600,0,0);

    BITMAP *buffer=create_bitmap(880,600);//(29*30,20*30)
    BITMAP *roca=nullptr;
    roca=load_bitmap("roca.bmp",NULL);
    pacbmp=load_bitmap("pacman.bmp",NULL);
    pacman=create_bitmap(33,33);//Dimensiones de un pacman
    comida=load_bitmap("Comida.bmp",NULL);

    while(!key[KEY_ESC] && game_over()){
         //rutina para mover a pacman
         if(key[KEY_RIGHT])
            dir=1;
         else if(key[KEY_LEFT])
            dir=0;
         else if(key[KEY_UP])
            dir=2;
         else if(key[KEY_DOWN])
            dir=3;

        if(dir==0){
            if(mapa[py/30][(px-30)/30]!='X')
               px=px-30;
            else
                dir=4;
        }
        else if(dir==1){
            if(mapa[py/30][(px+30)/30]!='X')
               px=px+30;
            else
                dir=4;
        }Curso Java. Servlets I. Vídeo 246
        else if(dir==2){
            if(mapa[(py-30)/30][(px)/30]!='X')
               py=py-30;
            else
                dir=4;
        }

        else if(dir==3){
            if(mapa[(py+30)/30][(px)/30]!='X')
               py=py+30;
            else
                dir=4;
        }

        //Rutina para atajo

        if(px<=-30)
           px=870;
        else if(px>=870)
            px=-30;

        clear(buffer);//borramos posiciones anteriores de pacman
        dibujar_mapa(buffer,roca);
        dibujar_personaje(buffer);
        pantalla(buffer);
        rest(150);//70 milisegundos para ejecutar la siguiente instrucion

        clear(pacman);
        blit(pacbmp,pacman,4*33,0,0,0,33,33);
        draw_sprite(buffer,pacman,px,py);
        pantalla(buffer);
        rest(90);
    }

    return 0;
}
END_OF_MAIN();

void dibujar_mapa(BITMAP *buffer,BITMAP *roca){
    int row,col;

    for(row=0;row<MAXFILAS;row++){
        for(col=0;col<MAXCOLS;col++){
            if(mapa[row][col]=='X'){
                draw_sprite(buffer,roca,col*30,row*30);//Imprimimos roca sobre buffer
            }
            else if(mapa[row][col]=='o'){
                draw_sprite(buffer,comida,col*30,row*30);
                if(py/30==row && px/30==col)
                   mapa[row][col]=' ';

            }
        }
    }
}
void pantalla(BITMAP *buffer){
    blit(buffer,screen,0,0,0,0,880,600);//imprimimos el buffer sobre la pantalla

}
void dibujar_personaje(BITMAP *buffer){
    blit(pacbmp,pacman,dir*33,0,0,0,33,33);
    draw_sprite(buffer,pacman,px,py);//para respetar transparencia

}
bool game_over(){
    int row,col;

    for(row=0;row<MAXFILAS;row++){
        for(col=0;col<MAXCOLS;col++){
            if(mapa[row][col]=='o')
                return true;
        }
    }
    return false;
}
*/
