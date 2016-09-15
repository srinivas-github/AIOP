#include <cstdio>
#include <cstring>
#include <cstdlib>


/**
 * command type
 */
typedef enum command
{
    PLACE = 0x51,
    CLEAR,
    MOVE,
    DUMP,
    SHOW,
    RESET,
    ERRCMD
}CommandType;

/**
 * Color object
 */
typedef enum color
{
    GREEN = 0x102,
    YELLOW,
    BLACK,
    WHITE,
    BLUE,
    RED,
    ERRC
}Color;


/**
 * Object defs
 */
typedef enum object
{
    BALL = 0x201,
    PEN,
    ERASER,
    PHONE,
    WALLET,
    ERRO

}Object;

/**
 * Container type
 */
typedef enum containrertype
{
    POCKET = 0x301,
    BAG,
    DRAWER,
    NOTCONT,
    ERRCONT
}ContainerType;
 
/**
 * Surface Type
 */
typedef enum surfacetype
{
    SHELF = 0x401,
    DESKTOP,
    FLOOR,
    NOTSUR,
    ERRSUR
}SurfaceType;

/**
 * Place types
 */
typedef struct placetype
{
    ContainerType containerType;
    SurfaceType surfaceType;
}PlaceType;


/**
 * Color and Object 
 */
typedef struct colorandobject
{
    Color color;
    Object object;
}ColorAndObject;



/**
 * struct Container
 */
typedef struct container
{
    int pocket;
    int bag;
    int drawer;
    ColorAndObject colorObj;
}Container;

/**
 * struct surface
 */
typedef struct surface
{
    int shelf;
    int desktop;
    int floor;
    ColorAndObject colorObj;

}Surface;


/**
 * struct destination
 */
typedef struct destination
{
    Container container;
    Surface surface;
}Destination;


/**
 * get the command type
 */
CommandType getCmd(char* cmd)
{
    CommandType cmdType;
    if (strcmp(cmd, "place") == 0)
        cmdType = PLACE;
    else if (strcmp(cmd, "clear") == 0)
        cmdType = CLEAR;
    else if (strcmp(cmd, "move") == 0)
        cmdType = MOVE;
    else if (strcmp(cmd, "show") == 0)
        cmdType = SHOW;
    else if (strcmp(cmd, "dump") == 0)
        cmdType = DUMP;
    else if (strcmp(cmd, "reset") == 0)
        cmdType = RESET;
    else
        cmdType = ERRCMD;

    return cmdType; 
}

/**
 * get color type
 */
Color getColor(char* col)
{
    Color colType;

    if (strcmp(col, "green") == 0)
        colType = GREEN;
    else if (strcmp(col, "yellow") == 0)
        colType = YELLOW;
    else if (strcmp(col, "black") == 0)
        colType = BLACK;
    else if (strcmp(col, "white") == 0)
        colType = WHITE;
    else if (strcmp(col, "blue") == 0)
        colType = BLUE;
    else if (strcmp(col, "red") == 0)
        colType = RED;
    else
        colType = ERRC;

    return colType;

}

/**
 * get the object type
 */
Object getObject(char* obj)
{
    Object objType;

    if (strcmp(obj, "ball") == 0)
        objType = BALL;
    else if (strcmp(obj, "pen") == 0)
        objType = PEN;
    else if (strcmp(obj, "eraser") == 0)
        objType = ERASER;
    else if (strcmp(obj, "phone") == 0)
        objType = PHONE;
    else if (strcmp(obj, "wallet") == 0)
        objType = WALLET;
    else 
         objType = ERRO;
    return objType;

}

/**
 * get the container type
 */
ContainerType getContainer(char* cnt)
{
    printf("Received container: %s\n", cnt);
    ContainerType cntType;

    if (strcmp(cnt, "pocket")== 0)
    {
        cntType = POCKET;
        printf("assigned pocket....");
    }
    else if (strcmp(cnt, "bag") == 0)
    {
        cntType = BAG;
    }
    else if (strcmp(cnt, "drawer") == 0)
        cntType = DRAWER;
    else 
        cntType = ERRCONT;

    
    return cntType;
}


/**
 * get the surface type
 */
SurfaceType getSurfaceType(char* surf)
{
    SurfaceType surfType;
    if (strcmp(surf, "shelf") == 0)
        surfType = SHELF;
    else if (strcmp(surf, "desktop") == 0)
        surfType = DESKTOP;
    else if(strcmp(surf, "floor") == 0)
        surfType = FLOOR;
    else 
        surfType = ERRSUR;

    return surfType;
}

/**
 * Populate a destination
 */
void populateDest(Color color, Object object, PlaceType place, Destination** dest)
{
    printf("populateDest received objects are:\n");
    printf("color: %d\n", color);
    printf("object: %d\n", object);
    printf("Container: %d\n", place.containerType);
    printf("Surface: %d\n", place.surfaceType);


    Destination* newDest = (Destination*)malloc(sizeof(Destination));
    
}

/**
 * clear destination
 */
void clearDestination(PlaceType place, Destination** dest)
{
}

/**
 * move destination
 */
void moveDestination(PlaceType place, Destination** dest)
{
}

void dump(Destination** dest)
{
}

void reset(Destination** dest)
{
} 

int main()
{
    char buf[255];
    memset(buf, 0, 255);
    CommandType cmdType = ERRCMD;
    Color colType = ERRC;
    Object objType = ERRO;
    ContainerType cntType = ERRCONT;
    SurfaceType surfType = ERRSUR;

    PlaceType placeType;
    Destination *destination;

    while ((fgets(buf, 255,stdin)) != NULL)
    {
       printf("%s\n", buf);
       char *word;
        //printf("Splitting the string \"%s\" into tokens:\n", buf);
        word = strtok(buf, " ");
        printf("Command Type:%d\n\n", cmdType);
        cmdType = getCmd(word);

        switch (cmdType)
        {
            case PLACE:
                //get the color type
                word = strtok(NULL, " ");
                colType = getColor(word);
                printf("Color type: %d\n", colType);
                if (colType != ERRC)
                {
                    //get the object type
                    word = strtok(NULL, " ");
                    objType = getObject(word);
                    printf("Object type:%d\n", objType);
                    if (objType != ERRO)
                    {
                        //check if the next word is "in" or "on"
                        printf("Inside object condition, checking for in or on\n\n");

                        word = strtok(NULL, " ");
                        printf("in or on :%s\n", word);
                        if (strcmp(word, "in") == 0)
                        {
                            
                            //get the container type
                            word = strtok(NULL, " ");
                            cntType = getContainer(word);
                            printf("Container type: %d\n", cntType);
                            if (cntType != ERRCONT)
                            {
                                placeType.containerType = cntType;
                                placeType.surfaceType = NOTSUR;
                                populateDest(colType, objType, placeType, &destination);
                            }
                            else
                                printf("Error in the cmd (container)...please try again\n\n");
                            
     
                        }
                        else if(strcmp(word, "on") == 0)
                        {
                            //get the surface type
                            word = strtok(NULL, " ");
                            surfType = getSurfaceType(word);
                            printf("Surface Type: %d\n", surfType);
                            if (surfType != ERRSUR)
                            {
                                placeType.surfaceType = surfType;
                                placeType.containerType = NOTCONT;
                                populateDest(colType, objType, placeType, &destination);
                            }
                            else
                                printf("Error in the cmd (surface)... please try again\n\n");
                        }
                        else
                            printf("Error in the command (no in or on)... please try again..\n\n");
                    }
                }
 
            break;
            case CLEAR:
                printf("clear cmd received\n\n");
            break;
            case MOVE:
                printf("move cmd recevied\n\n");
            break;
            case SHOW:
                printf("sow cmd recevied\n\n");
            break;
            case DUMP:
                printf("dump cmd received\n\n");
            break;
            case RESET:
                printf("reset cmd received\n\n");
            break;
            default:
                printf("Invalid Command.. please try again\n\n");
            break;
           
        } //end of switch
    } //end of while             
    
    return 0;
}


/**
 * Another Sample to get individual words
 */
/* get the first word from the message, seperated by
	 * space character */
//	 char* word;
//	 word = strtok(message, " ");
//         printf("1st word: %s\n", word);
/* get the second word from the message, NULL must be
* used to get tokens from the previous string now */
//word = strtok(NULL, " ");
//printf("2nd word: %s\n", word);
/* the following loop gets the rest of the words until the
 * end of the message */
//while ((word = strtok(NULL, " ")) != NULL)
//printf("Next: %s\n", word);
//return 0;
