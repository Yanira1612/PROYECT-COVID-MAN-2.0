#include <allegro.h>
#include "Covid_man.cpp"
#include "Casa.cpp"
#include "Vacuna.cpp"
#include <iostream>
#include <cstdlib>
//buffer y el mapa tienen las mismas dimensiones
using namespace std;
const char* CantPuntos[]={"0","1","2","3","4","5","6","7","8","9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20",
                          " 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30","31"," 32"," 33"," 34"," 35"," 36"," 37"," 38"," 39"," 40",
                          " 41"," 42"," 43"," 44"," 45"," 46"," 47"," 48"," 49"," 50","51"," 52"," 53"," 54"," 55"," 56"," 57"," 58"," 59"," 60",
                          " 61"," 62"," 63"," 64"," 65"," 66"," 67"," 68"," 69"," 70","71"," 72"," 73"," 74"," 75"," 76"," 77"," 78"," 79"," 80",
                          " 81"," 82"," 83"," 84"," 85"," 86"," 87"," 88"," 89"," 90","91"," 92"," 93"," 94"," 95"," 96"," 97"," 98"," 99","  100",
                          "  101","  102","  103","  104","  105","  106","  107","  108","  109","  110","  111","  112","  113","  114","  115","  116","  117","  118","  119","  120",
                          "  121","  122","  123","  124","  125","  126","  127","  128","  129","  130","  131","  132","  133","  134","  135","  136","  137","  138","  139","  140",
                          "  141","  142","  143","  144","  145","  146","  147","  148","  149","  150","  151","  152","  153","  154","  155","  156","  157","  158","  159","  160",
                          "  161","  162","  163","  164","  165","  166","  167","  168","  169","  170","  171","  172","  173","  174","  175","  176","  177","  178","  179","  180",
                          "  181","  182","  183","  184","  185","  186","  187","  188","  189","  190","  191","  192","  193","  194","  195","  196","  197","  198","  199","  200",
                          "  201","  202","  203","  204","  205","  206","  207","  208","  209","  210","  201","  212","  213","  214","  215","  216","  217","  218","  219","  220"};
class Mapa{
    private:
    bool salida=false;
    bool entrar=true;
    //musica
    //SAMPLE *muerte= load_wav("muerte.wav");
    MIDI *musica= load_midi("musica_fondo.mid");
    SAMPLE *recoger= load_wav("recoger.wav");

    BITMAP *fondo1=load_bitmap("FONDO1.bmp",NULL);
    BITMAP *fondo2=load_bitmap("FONDO2.bmp",NULL);
    BITMAP *fondo3=load_bitmap("FONDO3.bmp",NULL);
    BITMAP *cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP *over=load_bitmap("over.bmp",NULL);
    BITMAP *win=load_bitmap("win.bmp",NULL);
    BITMAP *pausa=load_bitmap("PAUSA.bmp",NULL);
    //Buffer buffer;//Creamos un bitmap en la RAM
    //Casa casa;//Imagen casa
    int nivel;//nivel en el que se encuentra el mapa
    int ejeX;
    int ejeY;
    int puntos=0;
    Covid_man jugador;
    Casa* casa=new Casa();

    Pastilla* pastilla=new Pastilla();
    Vacuna* vacuna=new Vacuna();
    Enfermo enemigo1{"enemigo1.bmp"};
    Enfermo enemigo2{"enemigo2.0.bmp"};
    Enfermo enemigo3;
    public:
    Mapa(int,int,int);//(nombrefichero,nivel,ejex,ejey)
    ~Mapa();
    void Mostrar();//mOSTRAMOS TODO EL COMPORTAMIENTO DEL JUEGO EN LA PANTALLA
    void dibujar_mapa();//Creamos el mapa con todos sus componentes
    void pantalla();//Creamos el buffer enciam de la ventana
    void Proceso();//mOSTRAMOS TODO EL COMPORTAMIENTO DEL JUEGO EN LA PANTALLA
    bool Win();//Nos indica si hemos ganado un determinado nivel
    void avanzarNivel();//Para avanzar a un siguiente nivel
    const char* pantallaNivel();//dEFINIMOS EL NIVEL EN EL QUE ESTA EL MAPA
    void mostrarNivelMapa();//Mostramos el nivel del mapa en pantalla
    const char* cantidadPuntos();//Nos devolvera cuantos puntos tiene el jugador
    void imprimirPuntosPantalla();//Imprimiremos los puntos en pantalla
    void mostrarPausa();
    void cruce();
    void mostrarWin(bool);
    void mostrarOver(bool);
    void menu();

    void setNivelMapa(int);
    int getNivelMapa();
    void setEjeX(int);
    int getEjeX();
    void setEjeY(int);
    int getEjeY();
    int getPuntos();
    void setPuntos(int);


};

