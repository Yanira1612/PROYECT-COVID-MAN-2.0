#include <cstdlib>
#include "Personaje.h"
class Enfermo : public Personaje{
	private:
    BITMAP *enemigobmp=NULL;//Creara un espacio en donde estara el enemigo
    BITMAP *enemigo=NULL;//Dimensiones de un pacman;//Imagen del enemigo
    int E_dir;
    int E_x,E_y; //coordenadas	 en el mapa
    int numMapa;
    public:
    Enfermo();
    Enfermo(const char*);
    ~Enfermo();
    int getPosX();
    int getPosY();
    void setNumMapa(int);
    void dibujar();
    void movimiento();
    void atajo(int);

};
Enfermo::Enfermo(const char* nombre){

    this->enemigobmp=load_bitmap(nombre,NULL);//Creara un espacio en donde estara el enemigo
    this->enemigo=create_bitmap(30,30);//Dimensiones de un pacman;//Imagen del enemigo
    this->E_dir=0;
    this->E_x=30*14;
    this->E_y=30*15; //coordenadas	 en el mapa
    this->numMapa=1;
}
Enfermo::Enfermo(){
    this->enemigobmp=load_bitmap("enemigo1.bmp",NULL);//Creara un espacio en donde estara el enemigo
    this->enemigo=create_bitmap(30,30);//Dimensiones de un pacman;//Imagen del enemigo
    this->E_dir=0;
    this->E_x=30*14;
    this->E_y=30*15; //coordenadas	 en el mapa
    this->numMapa=1;
}
Enfermo::~Enfermo(){

}
void Enfermo::setNumMapa(int numMapa){
   this->numMapa=numMapa;
}
int Enfermo::getPosX(){
   return E_x;
}
int Enfermo::getPosY(){
   return E_y;
}
void Enfermo::dibujar(){
	blit(enemigobmp,enemigo,0,0,0,0,30,30);
    draw_sprite(buffer.buffer,enemigo,E_x,E_y);//para respetar transparencia
}
void Enfermo::movimiento(){
	Enfermo::dibujar();

	if(numMapa==1){
        if (E_dir==0){
		   if( mapa1 [E_y/30][(E_x-30)/30] != 'X')
			  E_x-=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
        }
	    else if(E_dir==1){
		   if( mapa1 [E_y/30][(E_x+30)/30] != 'X')
			  E_x+=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	       }

	    else if(E_dir==2){
		   if( mapa1 [(E_y-30)/30][E_x/30] != 'X')
			  E_y-=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	    }

	    else if(E_dir==3){
		   if( mapa1 [(E_y+30)/30][E_x/30] != 'X')
			  E_y+=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	    }
	}//fin numMapa==1
	else if(numMapa==2){
        if (E_dir==0){
		   if( mapa2 [E_y/30][(E_x-30)/30] != 'X')
			  E_x-=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
        }
	    else if(E_dir==1){
		   if( mapa2 [E_y/30][(E_x+30)/30] != 'X')
			  E_x+=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	       }

	    else if(E_dir==2){
		   if( mapa2 [(E_y-30)/30][E_x/30] != 'X')
			  E_y-=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	    }

	    else if(E_dir==3){
		   if( mapa2 [(E_y+30)/30][E_x/30] != 'X')
			  E_y+=30;
		   else
			  E_dir=rand()%4; //valor al azar entre 0 y 3
	    }
	}//fin numMapa==2
	// movimiento para los atajos
	Enfermo::atajo(numMapa);
}
void Enfermo::atajo(int numMapa){
    if(numMapa==1){//Deinicion del atajo del mapa 1
        if(E_x<=-30 && E_y==270){
            E_x=870;E_y=270;
        }
        else if(E_x>=870 && E_y==270){
            E_x=-30;E_y=270;
        }
        else if(E_x<=-30 && E_y==540){
            E_x=870;E_y=30;
        }
        else if(E_x>=870 && E_y==30){
            E_x=-30;E_y=540;
        }
        else if(E_x>=870 && E_y==330){
            E_x=870;E_y=540;
        }
        else if(E_x>=870 && E_y==540){
            E_x=870;E_y=330;
        }
   }
   else if(numMapa==2){
        if(E_x<=-30 && E_y==270){
            E_x=870;E_y=270;
        }
        else if(E_x>=870 && E_y==270){
            E_x=-30;E_y=270;
        }
        else if(E_x<=-30 && E_y==540){
            E_x=870;E_y=30;
        }
        else if(E_x>=870 && E_y==30){
            E_x=-30;E_y=540;
        }
        else if(E_x>=870 && E_y==330){
            E_x=870;E_y=540;
            E_dir=0;//Para que vaya en la direccion correcta ya que el taajo entrada y salida estan en el mismo muro
        }
        else if(E_x>=870 && E_y==540){
            E_x=870;E_y=330;
            E_dir=0;//Para que vaya en la direccion correcta
        }
   }
}

/*
#include <allegro.h>
#include <cstdlib>
class Enfermo{
	private:
    BITMAP *enemigobmp=load_bitmap("enemigo.bmp",NULL);//Creara un espacio en donde estara el enemigo
    BITMAP *enemigo=create_bitmap(30,30);//Dimensiones de un pacman;//Imagen del enemigo
    int E_dir=0;
    int E_x=30*14,E_y=30*15; //coordenadas	 en el mapa

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

	if (E_dir==0){
		if( mapa [E_y/30][(E_x-30)/30] != 'X')
			E_x-=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 3
	}
	if(E_dir==1){
		if( mapa [E_y/30][(E_x+30)/30] != 'X')
			E_x+=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 3
	}

	if(E_dir==2){
		if( mapa [(E_y-30)/30][E_x/30] != 'X')
			E_y-=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 3
	}

	if(E_dir==3){
		if( mapa [(E_y+30)/30][E_x/30] != 'X')
			E_y+=30;
		else
			E_dir=rand()%4; //valor al azar entre 0 y 3
	}
	// movimiento para los atajos
	if( E_x<=-30)
		E_x=870;
		else if(E_x >= 870)
			E_x=-30;
}
*/
