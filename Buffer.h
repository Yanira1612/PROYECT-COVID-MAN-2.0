#define MAXFILAS 20 //Para el eje y (19)
#define MAXCOLS  31 //Parael eje x (30)
char mapa1[MAXFILAS][MAXCOLS]={
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X o    o    XXXXX    o       ",
        "X XXX XXXXX XXXXX XXXXX XXX X",
        "X XXX XXXXX XXXXX XXXXX XXX X",
        "X            o              X",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X     XX     XXX     XX     X",
        "X XXX XXXXXX XXX XXXXXXoXXX X",
        "X XXX XX             XX XXX X",
        "      XX XXXXXXXXXXX XX      ",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XXX XX             XX XXX X",
        "X XXX XXXXXX XXX XXXXXX XXX X",
        "X     XX     XXX  o  XX     X",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XXX                   XXX X",
        "X XXX XXXX XXXXXXXX XXX XXX X",
        "X XXX XXXX          XXX XXX X",
        "           XXXXXXXX         X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };
char mapa2[MAXFILAS][MAXCOLS]={
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X           XXXXX            ",
        "X XXX XXXXX XXXXX XXXXX XXX X",
        "X XXX                   XXX X",
        "X          o                X",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X     XX  o  XXX     XX     X",
        "X XXX XXXXXX XXX XXXXXX X X X",
        "X XXX XX       o     XX X X X",
        "      XX XXXXXXXXXXX XX      ",
        "X XXX XX XXXX   XXXX XX XXX X",
        "X XXX XX             XX XXX  ",
        "X XXX XXXXXX XXX XXXXXX XXX X",
        "X     XX     XXX     XX     X",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XXX  o       o        XXX X",
        "X XXX XXXX XXXXXXXX XXX XXX X",
        "X XXX XXXX          XXX XXX X",
        "           XXXXXXXX          ",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };
struct Buffer{
    BITMAP *buffer;
    int ejeX=880;
    int ejeY=700;

}buffer;
