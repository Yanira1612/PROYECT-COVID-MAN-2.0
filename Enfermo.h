
#include <allegro.h>
#include <cstdlib>
class Enfermo{
	private:
    BITMAP *enemigobmp=load_bitmap("enemigo.bmp",NULL);//Creara un espacio en donde estara el enemigo
    BITMAP *enemigo=create_bitmap(30,30);//Dimensiones del enfermo;//Imagen del enemigo
    int E_dir=0; // posicion inicial del enemigo
    int E_x=30*14,E_y=30*15; //coordenadas en el mapa donde aparecera

    public:
    void dibujarEnemigo();
    void moverEnemigo();

};

void Enfermo::dibujarEnemigo(){

	blit(enemigobmp,enemigo,0,0,0,0,30,30);
    draw_sprite(buffer.buffer,enemigo,E_x,E_y);//para respetar transparencia
}
void Enfermo::moverEnemigo(){
	Enfermo::dibujarEnemigo();

	if (E_dir==0){	//movimiento hacia la izquierda
		if( mapa1[E_y/30][(E_x-30)/30] != 'X')
			E_x-=30;
		else		//para cuando haya un muro
			E_dir=rand()%4; //valor al azar entre 0 y 4
	}
	if(E_dir==1){	//movimiento hacia la derecha
		if( mapa1[E_y/30][(E_x+30)/30] != 'X')
			E_x+=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 4
	}

	if(E_dir==2){//movimiento hacia la arriba
		if( mapa1[(E_y-30)/30][E_x/30] != 'X')
			E_y-=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 4
	}

	if(E_dir==3){	//movimiento hacia la abajo
		if( mapa1[(E_y+30)/30][E_x/30] != 'X')
			E_y+=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 4
	}
	// movimiento para los atajos
	if( E_x<=-30) // si es menos a -30 en el mapa se redirecciona al costado izquiero
		E_x=870;
		else if(E_x >= 870) // si es menos a -30 en el mapa se redirecciona al costado derecho
			E_x=-30;
}

