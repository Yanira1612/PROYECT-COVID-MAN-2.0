#include <allegro.h>
#include "Enfermo.cpp"
class Covid_man : public Personaje{
    private:
    SAMPLE *muerte=NULL;
    BITMAP *pacbmp=NULL;//Creara un espacio en donde estara pacman
    BITMAP *muertebmp=NULL;
    BITMAP *pacman=NULL;//Dimensiones de un pacman;//Imagen pacman
    int dir;//para que pacman no se mueva al iniciar el juego
    int px,py;//posicion adecuada de pacman
    int numMapa;
    int vidas;
    public:
    Covid_man();
    ~Covid_man();

    SAMPLE* getMusicMuerte();
    BITMAP* getMuertebmp();
    void setPacman(BITMAP* pacman);
    BITMAP* getPacman();

    int getVida();
    const char* imprimirVida(int);
    void setVida(int);
    int getPosX();//
    int getPosY();//
    void setNumMapa(int);//
    void movimiento();//
    void dibujar();//
    void morderPacman();
    void inicioMuerte();
    void finalMuerte(int);
    void atajo(int);//
    void ganarVida(int puntos);

};
