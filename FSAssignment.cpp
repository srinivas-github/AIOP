#include <cstdio>
#include <cstring>
#include <cstdlib>


/**
 * command type
 */
typedef enum command
{
    PLACE = 1,
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
    GREEN = 8,
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
    BALL = 15,
    PEN,
    ERASER,
    PHONE,
    WALLET,
    ERRO
}Object;


/**
 * Storage Type (Container/Surface)
 */
typedef enum storageType
{
    POCKET = 21,
    BAG,
    DRAWER,
    SHELF,
    DESKTOP,
    FLOOR,
    ERRSTORAGE
}StorageType;

/**
 * Color and Object 
 */
typedef struct colorandobject
{
    Color color;
    Object object;
}ColorAndObject;



/**
 * Container defs
 */
typedef struct pocketCont
{
    int count;
    ColorAndObject clrAndObj;
}PocketCont;

typedef struct bagCont
{
    int count;
    ColorAndObject clrAndObj;
}BagCont;

typedef struct drawerCont
{
    int count;
    ColorAndObject clrAndObj;
}DrawerCont;

/**
 * struct Container
 */
typedef struct container
{
    PocketCont pocket;
    BagCont bag;
    DrawerCont drawer;
}Container;

/**
 * surface defs
 */
typedef struct shelfSur
{
    int count;
    ColorAndObject clrAndObj;
}ShelfSurface; 
 
typedef struct desktopSur
{
    int count;
    ColorAndObject clrAndObj;
}DesktopSurface; 

typedef struct floorSur
{
    int count;
    ColorAndObject clrAndObj;
}FloorSurface; 

typedef struct surface
{
    ShelfSurface shelf;
    DesktopSurface desktop;
    FloorSurface floor;
}Surface;

/**
 * Destination
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
    printf("Received Command: %s\n", cmd);
    if (strncmp(cmd, "place", 5) == 0)
    {
        printf(" assign place command...\n");
        cmdType = PLACE;
    }
    else if (strncmp(cmd, "clear", 5) == 0)
    {
        cmdType = CLEAR;
    }
    else if (strncmp(cmd, "move", 4) == 0)
    {
        cmdType = MOVE;
    }
    else if (strncmp(cmd, "show", 4) == 0)
    {
        cmdType = SHOW;
    }
    else if (strncmp(cmd, "dump", 4) == 0)
    {
        cmdType = DUMP;
    }
    else if (strncmp(cmd, "reset", 5) == 0)
    {
        cmdType = RESET;
    }
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
    printf("Received Color: %s\n", col);
   
    if (strncmp(col, "green", 5) == 0)
    {
        colType = GREEN;
    }
    else if (strncmp(col, "yellow", 6) == 0)
    {
        colType = YELLOW;
        printf("yellow color assign..\n");
    }
    else if (strncmp(col, "black", 5) == 0)
    {
        colType = BLACK;
    }
    else if (strncmp(col, "white", 5) == 0)
    {
        colType = WHITE;
    }
    else if (strncmp(col, "blue", 4) == 0)
    {
        colType = BLUE;
    }
    else if (strncmp(col, "red", 3) == 0)
    {
        colType = RED;
    }
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
    printf("Object received: %s\n", obj);

    if (strncmp(obj, "ball", 4) == 0)
    {
        objType = BALL;
    }
    else if (strncmp(obj, "pen", 3) == 0)
    {
        objType = PEN;
    }
    else if (strncmp(obj, "eraser", 6) == 0)
    {
        printf("eraser object assign...\n");
        objType = ERASER;
    }
    else if (strncmp(obj, "phone", 5) == 0)
    {
        objType = PHONE;
    }
    else if (strncmp(obj, "wallet", 6) == 0)
    {
        objType = WALLET;
    }
    else
    {  
         objType = ERRO;
    }

    return objType;
}

/**
 * get the storage type
 */
StorageType getStorageType(char* store)
{
    printf("Received container: %s\n", store);
    StorageType storeType;

    if (strncmp(store, "pocket", 6) == 0)
         storeType = POCKET;
    else if (strncmp(store, "bag", 3) == 0)
        storeType = BAG;
    else if (strncmp(store, "drawer", 6) == 0)
        storeType = DRAWER;
    else if (strncmp(store, "shelf",5) == 0)
        storeType = SHELF;
    else if (strncmp(store, "desktop", 7) == 0)
        storeType = DESKTOP;
    else if(strncmp(store, "floor", 5) == 0)
        storeType = FLOOR;
    else
		storeType = ERRSTORAGE;
	
    return storeType;
}


/**
 * Populate a destination
 */
void populateDest(Color color, Object object, StorageType storeType, Destination* tempDest, Destination** mainDest)
{
    printf("populateDest received objects are:\n");
    printf("color: %d\n", color);
    printf("object: %d\n", object);
    printf("Storage: %d\n", storeType);

    Destination* newDest = (Destination*)malloc(sizeof(Destination));
    switch(storeType)
    {
        case POCKET:
            if ( tempDest->container.pocket.count == 1)
            {
                printf("pocket is full\n");
            }
            else
            {
                printf("Storing object: %d color: %d in Pocket\n", object, color);
                newDest->container.pocket.count = 1;
                newDest->container.pocket.clrAndObj.color = color;
                newDest->container.pocket.clrAndObj.object = object;
                *mainDest = newDest;
            }
        break;
        default:
        break;
    } 
}

/**
 * clear destination
 */
void clearDestination(StorageType storeType, Destination** dest)
{
}

/**
 * move destination
 */
void moveDestination(StorageType storeType, Destination** dest)
{
}

void dump(Destination** dest)
{
}

void reset(Destination** dest)
{
} 



/**
 * Global Destination
 */
Destination destination; // = NULL;
int main()
{
    char buf[255];
    memset(buf, 0, 255);
    CommandType cmdType = ERRCMD;
    Color colType = ERRC;
    Object objType = ERRO;
    StorageType storeType = ERRSTORAGE;

    Destination *dest = NULL;
    Destination *mainDest = NULL;

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
                        word = strtok(NULL, " ");
                        printf("in or on :%s\n", word);
                        if ( strncmp(word, "in", 2) == 0 || strncmp(word, "on", 2) == 0)
                        {
                            //get the storage type
                            word = strtok(NULL, " ");
                            storeType = getStorageType(word);
                            printf("Store type: %d\n", storeType);
                            if (storeType!= ERRSTORAGE)
                            {
                                dest = mainDest;
                                populateDest(colType, objType, storeType, dest, &mainDest);
                                printf("After populate, Dest contains: color: %d, object: %d, count: %d\n\n", 
                                        mainDest->container.pocket.clrAndObj.color, 
                                        mainDest->container.pocket.clrAndObj.object,
                                        mainDest->container.pocket.count);
                    
                            }
                            else
                                printf("Error in the cmd(either IN or ON)...please try again\n\n");
                        }
                        else
                            printf("Error in the cmd (surface)... please try again\n\n");
                    }
                    else
                        printf("Erron in cmd, object is wrong..\n");
                }
                else
                    printf("Error in cmd, Color is not matching...\n");
 
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
