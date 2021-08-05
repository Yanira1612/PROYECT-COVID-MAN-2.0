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
