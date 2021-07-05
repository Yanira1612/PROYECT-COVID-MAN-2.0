#define MAXFILAS 20 //Para el eje y (19)
#define MAXCOLS  31 //Parael eje x (30)
char mapa1[MAXFILAS][MAXCOLS]={
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XoooooooooooXXXXXoooooooooooo",
        "X XXX XXXXX XXXXX XXXXX XXXoX",
        "X XXX XXXXX XXXXX XXXXX XXXoX",
        "X ooooooooooooooooooooooooooX",
        "X XXX XX XXXXXXXXXXX XX XXXoX",
        "X     XXoooooXXXoooooXX    oX",
        "X XXX XXXXXX XXX XXXXXXoXXXoX",
        "XXXXX XX             XX XXXXX",
        "ooooooXX XXXXXXXXXXX XXoooooo",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XXX XXoooooooooooooXX XXX X",
        "X XXX XXXXXX XXX XXXXXX XXX X",
        "XoooooXXoooooXXXoooooXXoooooX",
        "X XXX XX XXXXXXXXXXX XX XXXoX",
        "X XXXoooooooooooooooooooXXXoX",
        "X XXX XXXX XXXXXXXX XXX XXX X",
        "X XXX XXXX          XXX XXX X",
        " ooooooooooXXXXXXXXoooooooooX",
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
        "X XXX XX XXXX   XXXX XX XXXXX",
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
    BITMAP *buffer=NULL;
    int ejeX=880;
    int ejeY=700;

}buffer;


