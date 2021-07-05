#include <allegro.h>
#include "Buffer.h"
class Covid_man{
    private:
    BITMAP *pacbmp=load_bitmap("pacman.bmp",NULL);;//Creara un espacio en donde estara pacman
    BITMAP *muertebmp=load_bitmap("muerte.bmp",NULL);
    BITMAP *pacman=create_bitmap(33,33);//Dimensiones de un pacman;//Imagen pacman
    int dir=4;//para que pacman no se mueva al iniciar el juego
    int px=30*14,py=30*17;//posicion adecuada de pacman
    int numMapa=1;
    int vidas=3;
    public:
    BITMAP* getMuertebmp(){return muertebmp;}
    void setPacman(BITMAP* pacman){
       this->pacman=pacman;
    }
    BITMAP* getPacman(){
       return this->pacman;
    }

    int getVida();
    void setVida(int);
    int getPosX();
    int getPosY();
    void setNumMapa(int);
    void movimientoPacman();
    void dibujarPacman();
    void morderPacman();
    void muertePacman(int,int);
    void atajo(int);

};
void Covid_man::movimientoPacman(){
    if(key[KEY_LEFT])
            dir=0;
    else if(key[KEY_RIGHT])
            dir=1;
    else if(key[KEY_UP])
            dir=2;
    else if(key[KEY_DOWN])
            dir=3;

    if(numMapa==1){//Nivel 1 del juego
        if(dir==0){
          if(mapa1[py/30][(px-30)/30]!='X')//Evitamos que pacman cruce los muros
             px=px-30;
          else
             dir=4;
        }
        else if(dir==1){
           if(mapa1[py/30][(px+30)/30]!='X')
             px=px+30;
           else
             dir=4;
        }
        else if(dir==2){
           if(mapa1[(py-30)/30][(px)/30]!='X')
             py=py-30;
           else
             dir=4;
         }

        else if(dir==3){
           if(mapa1[(py+30)/30][(px)/30]!='X')
              py=py+30;
           else
              dir=4;
        }
    }
    else if(numMapa==2){//Nivel 2 del juego
        if(dir==0){
          if(mapa2[py/30][(px-30)/30]!='X')//Evitamos que pacman cruce los muros
             px=px-30;
          else
             dir=4;
        }
        else if(dir==1){
           if(mapa2[py/30][(px+30)/30]!='X')
             px=px+30;
           else
             dir=4;
        }
        else if(dir==2){
           if(mapa2[(py-30)/30][(px)/30]!='X')
             py=py-30;
           else
             dir=4;
         }

        else if(dir==3){
           if(mapa2[(py+30)/30][(px)/30]!='X')
              py=py+30;
           else
              dir=4;
        }
    }
    Covid_man::atajo(numMapa);
    clear(buffer.buffer);//borramos posiciones anteriores de pacman
}
void Covid_man::dibujarPacman(){

    blit(pacbmp,pacman,dir*33,0,0,0,33,33);
    draw_sprite(buffer.buffer,pacman,px,py);//para respetar transparencia

}
void Covid_man::morderPacman(){
    clear(pacman);
    blit(pacbmp,pacman,4*33,0,0,0,33,33);
    draw_sprite(buffer.buffer,pacman,px,py);//para respetar transparencia

}
void Covid_man::atajo(int numMapa){
    if(numMapa==1){//Deinicion del atajo del mapa 1
        if(px<=-30 && py==270){
            px=870;py=270;
        }
        else if(px>=870 && py==270){
            px=-30;py=270;
        }
        else if(px<=-30 && py==540){
            px=870;py=30;
        }
        else if(px>=870 && py==30){
            px=-30;py=540;
        }
        else if(px>=870 && py==330){
            px=870;py=540;
        }
        else if(px>=870 && py==540){
            px=870;py=330;
        }
   }
   else if(numMapa==2){
        if(px<=-30 && py==270){
            px=870;py=270;
        }
        else if(px>=870 && py==270){
            px=-30;py=270;
        }
        else if(px<=-30 && py==540){
            px=870;py=30;
        }
        else if(px>=870 && py==30){
            px=-30;py=540;
        }
        else if(px>=870 && py==330){
            px=870;py=540;
            dir=0;//Para que vaya en la direccion correcta ya que el taajo entrada y salida estan en el mismo muro
        }
        else if(px>=870 && py==540){
            px=870;py=330;
            dir=0;//Para que vaya en la direccion correcta
        }
   }

}
int Covid_man::getPosX(){
    return px;
}
int Covid_man::getPosY(){
    return py;
}
void Covid_man::setNumMapa(int numMapa){//pARA SABER EN QUE MAPA ESTAMOS
    this->numMapa=numMapa;
}
int Covid_man::getVida(){
   return this->vidas;
}
void Covid_man::setVida(int vidas){
   this->vidas=vidas;
}
void Covid_man::muertePacman(int enemigoPOSx,int enemigoPOSy){
   if(Covid_man::getPosX()==enemigoPOSx && Covid_man::getPosY()==enemigoPOSy){
      vidas--;
      for(int i=0;i<6;i++){
         clear(pacman);
         clear(buffer.buffer);
         //dibujar_mapa();
         blit(muertebmp,pacman,i*33,0,0,0,33,33);
         draw_sprite(buffer.buffer,pacman,px,py);

         blit(buffer.buffer,screen,0,0,0,0,buffer.ejeX,buffer.ejeY);//pantalla()
         rest(70);
      }
   }
}


//Enfermo

#include <cstdlib>
class Enfermo{
	private:
    BITMAP *enemigobmp=load_bitmap("enemigo.bmp",NULL);;//Creara un espacio en donde estara el enemigo
    BITMAP *enemigo=create_bitmap(30,30);//Dimensiones de un pacman;//Imagen del enemigo
    int E_dir=0;
    int E_x=30*14,E_y=30*15; //coordenadas	 en el mapa
    int numMapa=1;
    public:
    int getPosX();
    int getPosY();
    void setNumMapa(int);
    void dibujarEnemigo();
    void movimientoEnemigo();
    void atajo(int);

};
void Enfermo::setNumMapa(int numMapa){
   this->numMapa=numMapa;
}
int Enfermo::getPosX(){
   return E_x;
}
int Enfermo::getPosY(){
   return E_y;
}
void Enfermo::dibujarEnemigo(){
	blit(enemigobmp,enemigo,0,0,0,0,30,30);
    draw_sprite(buffer.buffer,enemigo,E_x,E_y);//para respetar transparencia
}
void Enfermo::movimientoEnemigo(){
	Enfermo::dibujarEnemigo();

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
