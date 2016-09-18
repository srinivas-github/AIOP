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
    RESETC,
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
    RESETO,
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


bool isStorageEmpty(StorageType storeType, Destination dest)
{
    bool bResult = false;

    switch(storeType)
    {
        case POCKET:
            if (dest.container.pocket.count == 0)
                bResult = true;
         break;
         case BAG:
             if (dest.container.bag.count == 0)
                 bResult = true;
         break;
         case DRAWER:
             if (dest.container.drawer.count == 0)
                 bResult = true;
         break;
         case SHELF:
             if (dest.surface.shelf.count == 0)
                 bResult = true;
         break;
         case FLOOR:
             if (dest.surface.floor.count == 0)
                 bResult = true;
         break;
         case DESKTOP:
             if (dest.surface.desktop.count == 0)
                 bResult = true;
         break;

         default:
             printf("Error in isStorageEmpty\n");
         break;

    }
    return bResult;
}


/**
 * Populate a destination
 */
//void populateDest(Color color, Object object, StorageType storeType, Destination* tempDest, Destination** mainDest)
  void populateDest(Color color, Object object, StorageType storeType, Destination& dest)
{
    printf("populateDest received objects are:\n");
    printf("color: %d\n", color);
    printf("object: %d\n", object);
    printf("Storage: %d\n", storeType);

    if (!isStorageEmpty(storeType, dest))
    {
        printf("Error: Place is already full\n");
        return;
    }

    switch(storeType)
    {
        case POCKET:
            dest.container.pocket.count  = 1;
            dest.container.pocket.clrAndObj.color = color;
            dest.container.pocket.clrAndObj.object = object;
        break;
        case BAG:
            dest.container.bag.count = 1;
            dest.container.bag.clrAndObj.color = color;
            dest.container.bag.clrAndObj.object = object;
        break;
        case DRAWER:
            dest.container.drawer.count = 1;
            dest.container.drawer.clrAndObj.color = color;
            dest.container.drawer.clrAndObj.object = object;
        break;
        case SHELF:
            dest.surface.shelf.count = 1;
            dest.surface.shelf.clrAndObj.color = color;
            dest.surface.shelf.clrAndObj.object = object;
        break;
        case DESKTOP:
            dest.surface.desktop.count = 1;
            dest.surface.desktop.clrAndObj.color = color;
            dest.surface.desktop.clrAndObj.object = object;
        break;
        case FLOOR:
            dest.surface.floor.count = 1;
            dest.surface.floor.clrAndObj.color = color;
            dest.surface.floor.clrAndObj.object = object;
        break;
        default:
        break;
    } 
}


/**
 * clear destination
 */
void clearDest(StorageType storeType, Destination& dest)
{

    if (isStorageEmpty(storeType, dest))
    {
        printf("Place is already empty\n\n");
        return;
    }


    switch(storeType)
    {
        case POCKET:
                printf("Clearing the pocket container\n\n");
                dest.container.pocket.count  = 0;
                dest.container.pocket.clrAndObj.color = RESETC;
                dest.container.pocket.clrAndObj.object = RESETO;
         break;
         case BAG:
                printf("Clearing the bag container\n\n");
                dest.container.bag.count  = 0;
                dest.container.bag.clrAndObj.color = RESETC;
                dest.container.bag.clrAndObj.object = RESETO;
         break;
         case DRAWER:
             printf("Clearing the drawer container\n\n");
             dest.container.drawer.count = 0;
             dest.container.drawer.clrAndObj.color = RESETC;
             dest.container.drawer.clrAndObj.object = RESETO;
         break;
         case SHELF:
             printf("Clearing the shelf surface\n\n");
             dest.surface.shelf.count = 0;
             dest.surface.shelf.clrAndObj.color = RESETC;
             dest.surface.shelf.clrAndObj.object = RESETO;
         break;
         case FLOOR:
             printf("Clearing the floor surface\n\n");
             dest.surface.floor.count = 0;
             dest.surface.floor.clrAndObj.color = RESETC;
             dest.surface.floor.clrAndObj.object = RESETO;
         break;
         case DESKTOP:
             printf("Clearing the desktop surface\n\n");
             dest.surface.desktop.count = 0;
             dest.surface.desktop.clrAndObj.color = RESETC;
             dest.surface.desktop.clrAndObj.object = RESETO;
         break;
      
         default:
             printf("Error in clear storage\n");
         break;

    }
}



/**
 * move destination
 */
void moveDestination(StorageType fromStoreType, StorageType toStoreType, Destination& dest)
{
    /**
     * check if storage is empty
     */
    if (isStorageEmpty(fromStoreType, dest))
    {
        printf("Moving: Source container/surface is empty\n\n");
        return;
    }

    if ( !isStorageEmpty(toStoreType, dest))
    {
        printf("Moving: Destination contianer/surface is full\n\n");
        return;
    }
    
    if (fromStoreType == toStoreType)
    {
        printf("Can not move on the same container/surface...\n");
        return;
    }

    switch(fromStoreType)
    {
        case POCKET:
            dest.container.pocket.count = 0;
            switch(toStoreType)
            {
                case BAG:
                    dest.container.bag.count = 1;
                    dest.container.bag.clrAndObj.color =  dest.container.pocket.clrAndObj.color;
                    dest.container.bag.clrAndObj.object = dest.container.pocket.clrAndObj.object;
                break;
                case DRAWER:
                    dest.container.drawer.count = 1;
                    dest.container.drawer.clrAndObj.color =  dest.container.pocket.clrAndObj.color;
                    dest.container.drawer.clrAndObj.object = dest.container.pocket.clrAndObj.object;
                break;
                case SHELF:
                    dest.surface.shelf.count = 1;
                    dest.surface.shelf.clrAndObj.color =  dest.container.pocket.clrAndObj.color;
                    dest.surface.shelf.clrAndObj.object = dest.container.pocket.clrAndObj.object;

                break;
                 case DESKTOP:
                    dest.surface.desktop.count = 1;
                    dest.surface.desktop.clrAndObj.color =  dest.container.pocket.clrAndObj.color;
                    dest.surface.desktop.clrAndObj.object = dest.container.pocket.clrAndObj.object;
                break;
                case FLOOR:
                    dest.surface.floor.count = 1;
                    dest.surface.floor.clrAndObj.color =  dest.container.pocket.clrAndObj.color;
                    dest.surface.floor.clrAndObj.object = dest.container.pocket.clrAndObj.object;

                break;

            }
        break;
        case BAG:
            dest.container.bag.count = 0;
            switch(toStoreType)
            {
                case POCKET:
                    dest.container.pocket.count = 1;
                    dest.container.pocket.clrAndObj.color =  dest.container.bag.clrAndObj.color;
                    dest.container.pocket.clrAndObj.object = dest.container.bag.clrAndObj.object;
                break;
                case DRAWER:
                    dest.container.drawer.count = 1;
                    dest.container.drawer.clrAndObj.color =  dest.container.bag.clrAndObj.color;
                    dest.container.drawer.clrAndObj.object = dest.container.bag.clrAndObj.object;
                break;
                case SHELF:
                    dest.surface.shelf.count = 1;
                    dest.surface.shelf.clrAndObj.color =  dest.container.bag.clrAndObj.color;
                    dest.surface.shelf.clrAndObj.object = dest.container.bag.clrAndObj.object;

                break;
                 case DESKTOP:
                    dest.surface.desktop.count = 1;
                    dest.surface.desktop.clrAndObj.color =  dest.container.bag.clrAndObj.color;
                    dest.surface.desktop.clrAndObj.object = dest.container.bag.clrAndObj.object;
                break;
                case FLOOR:
                    dest.surface.floor.count = 1;
                    dest.surface.floor.clrAndObj.color =  dest.container.bag.clrAndObj.color;
                    dest.surface.floor.clrAndObj.object = dest.container.bag.clrAndObj.object;

                break;

            }

        break;
        case DRAWER:
             dest.container.drawer.count = 0;
            switch(toStoreType)
            {
                case BAG:
                    dest.container.bag.count = 1;
                    dest.container.bag.clrAndObj.color =  dest.container.drawer.clrAndObj.color;
                    dest.container.bag.clrAndObj.object = dest.container.drawer.clrAndObj.object;
                break;
                case POCKET:
                    dest.container.pocket.count = 1;
                    dest.container.pocket.clrAndObj.color =  dest.container.drawer.clrAndObj.color;
                    dest.container.pocket.clrAndObj.object = dest.container.drawer.clrAndObj.object;
                break;
                case SHELF:
                    dest.surface.shelf.count = 1;
                    dest.surface.shelf.clrAndObj.color =  dest.container.drawer.clrAndObj.color;
                    dest.surface.shelf.clrAndObj.object = dest.container.drawer.clrAndObj.object;

                break;
                 case DESKTOP:
                    dest.surface.desktop.count = 1;
                    dest.surface.desktop.clrAndObj.color =  dest.container.drawer.clrAndObj.color;
                    dest.surface.desktop.clrAndObj.object = dest.container.drawer.clrAndObj.object;
                break;
                case FLOOR:
                    dest.surface.floor.count = 1;
                    dest.surface.floor.clrAndObj.color =  dest.container.drawer.clrAndObj.color;
                    dest.surface.floor.clrAndObj.object = dest.container.drawer.clrAndObj.object;

                break;

            }

        break;
        case SHELF:
             dest.surface.shelf.count = 0;
             switch(toStoreType)
             {
                case POCKET:
                    dest.container.pocket.count = 1;
                    dest.container.pocket.clrAndObj.color  = dest.surface.shelf.clrAndObj.color;
                    dest.container.pocket.clrAndObj.object = dest.surface.shelf.clrAndObj.object;
                break;
                case BAG:
                    dest.container.bag.count = 1;
                    dest.container.bag.clrAndObj.color =  dest.surface.shelf.clrAndObj.color;
                    dest.container.bag.clrAndObj.object = dest.surface.shelf.clrAndObj.object;
                break;
                case DRAWER:
                    dest.container.drawer.count = 1;
                    dest.container.drawer.clrAndObj.color =  dest.surface.shelf.clrAndObj.color;
                    dest.container.drawer.clrAndObj.object = dest.surface.shelf.clrAndObj.object;
                break;
                case DESKTOP:
                    dest.surface.desktop.count = 1;
                    dest.surface.desktop.clrAndObj.color =  dest.surface.shelf.clrAndObj.color;
                    dest.surface.desktop.clrAndObj.object = dest.surface.shelf.clrAndObj.object;
                break;
                case FLOOR:
                    dest.surface.floor.count = 1;
                    dest.surface.floor.clrAndObj.color =  dest.surface.shelf.clrAndObj.color;
                    dest.surface.floor.clrAndObj.object = dest.surface.shelf.clrAndObj.object;

                break;

            }

        break;
        case DESKTOP:
            dest.surface.desktop.count = 0;
            switch(toStoreType)
            {
                case POCKET:
                    dest.container.pocket.count = 1;
                    dest.container.pocket.clrAndObj.color  = dest.surface.desktop.clrAndObj.color;
                    dest.container.pocket.clrAndObj.object = dest.surface.desktop.clrAndObj.object;
                break;
                case BAG:
                    dest.container.bag.count = 1;
                    dest.container.bag.clrAndObj.color =  dest.surface.desktop.clrAndObj.color;
                    dest.container.bag.clrAndObj.object = dest.surface.shelf.clrAndObj.object;
                break;
                case DRAWER:
                    dest.container.drawer.count = 1;
                    dest.container.drawer.clrAndObj.color =  dest.surface.desktop.clrAndObj.color;
                    dest.container.drawer.clrAndObj.object = dest.surface.desktop.clrAndObj.object;
                break;
                case SHELF:
                    dest.surface.shelf.count = 1;
                    dest.surface.shelf.clrAndObj.color =  dest.surface.desktop.clrAndObj.color;
                    dest.surface.shelf.clrAndObj.object = dest.surface.desktop.clrAndObj.object;
                break;
                case FLOOR:
                    dest.surface.floor.count = 1;
                    dest.surface.floor.clrAndObj.color =  dest.surface.desktop.clrAndObj.color;
                    dest.surface.floor.clrAndObj.object = dest.surface.desktop.clrAndObj.object;

                break;

            }
            
        break;
        case FLOOR:
            dest.surface.floor.count = 0;
             switch(fromStoreType)
              {
                case POCKET:
                    dest.container.pocket.count = 1;
                    dest.container.pocket.clrAndObj.color  = dest.surface.floor.clrAndObj.color;
                    dest.container.pocket.clrAndObj.object = dest.surface.floor.clrAndObj.object;
                break;
                case BAG:
                    dest.container.bag.count = 1;
                    dest.container.bag.clrAndObj.color =  dest.surface.floor.clrAndObj.color;
                    dest.container.bag.clrAndObj.object = dest.surface.floor.clrAndObj.object;
                break;
                case DRAWER:
                    dest.container.drawer.count = 1;
                    dest.container.drawer.clrAndObj.color =  dest.surface.floor.clrAndObj.color;
                    dest.container.drawer.clrAndObj.object = dest.surface.floor.clrAndObj.object;
                break;
                case SHELF:
                    dest.surface.shelf.count = 1;
                    dest.surface.shelf.clrAndObj.color =  dest.surface.floor.clrAndObj.color;
                    dest.surface.shelf.clrAndObj.object = dest.surface.floor.clrAndObj.object;
                break;
                case DESKTOP:
                    dest.surface.desktop.count = 1;
                    dest.surface.desktop.clrAndObj.color =  dest.surface.floor.clrAndObj.color;
                    dest.surface.desktop.clrAndObj.object = dest.surface.floor.clrAndObj.object;

                break;

            }

        break;
        default:
            printf("move command error....\n");
        break;
    }
   
}


/**
 * show
 */

void show(StorageType storeType, Destination dest)
{

    char colStr[25];
    char objStr[25];
    memset(colStr, 0, 25);
    memset(objStr, 0, 25);

    //check if the given place is empty
    if (isStorageEmpty(storeType, dest))
    {
        printf("Empty\n\n");
        return ;
    }
   
    switch (storeType)
    {
        case POCKET:
        case BAG:
        case DRAWER:
            switch(dest.container.pocket.clrAndObj.color)
            {
                case GREEN:
                    strncpy(colStr, "green", 5);
                break;
                case YELLOW:
                    strncpy(colStr, "yellow", 6);
                break;
                case BLACK:
                    strncpy(colStr, "black", 5);
                break;
                case WHITE:
                    strncpy(colStr, "white", 5);
                break;
                case RED:
                    strncpy(colStr, "red", 3);
                break;
                case BLUE:
                    strncpy(colStr, "blue", 4);
                break;
                default:
                break; 
            }
            switch(dest.container.pocket.clrAndObj.object)
            {
                case BALL:
                    strncpy(objStr, "ball", 4);
                break;
                case PEN:
                    strncpy(objStr, "pen", 3);
                break;
                case ERASER:
                    strncpy(objStr, "eraser", 6);
                break;
                case WALLET:
                    strncpy(objStr, "wallet", 6);
                break;
                case PHONE:
                    strncpy(objStr, "phone", 5);
                break;
                default:
                break;

            }
        break;
        case SHELF:
        case DESKTOP:
        case FLOOR:

            switch(dest.container.pocket.clrAndObj.color)
            {
                case GREEN:
                    strncpy(colStr, "green", 5);
                break;
                case YELLOW:
                    strncpy(colStr, "yellow", 6);
                break;
                case BLACK:
                    strncpy(colStr, "black", 5);
                break;
                case WHITE:
                    strncpy(colStr, "white", 5);
                break;
                case RED:
                    strncpy(colStr, "red", 3);
                break;
                case BLUE:
                    strncpy(colStr, "blue", 4);
                break;
                default:
                break;
            }
            switch(dest.container.pocket.clrAndObj.object)
            {
                case BALL:
                    strncpy(objStr, "ball", 4);
                break;
                case PEN:
                    strncpy(objStr, "pen", 3);
                break;
                case ERASER:
                    strncpy(objStr, "eraser", 6);
                break;
                case WALLET:
                    strncpy(objStr, "wallet", 6);
                break;
                case PHONE:
                    strncpy(objStr, "phone", 5);
                break;
                default:
                break;

            }      break;
        default:
        break;
    }
    printf("%s   %s\n\n", colStr, objStr);

}

void reset(Destination& dest)
{
    dest.container.pocket.count = 0;
    dest.container.pocket.clrAndObj.color  = RESETC;
    dest.container.pocket.clrAndObj.object = RESETO;

    dest.container.bag.count = 0;
    dest.container.bag.clrAndObj.color  = RESETC;
    dest.container.bag.clrAndObj.object = RESETO;

    dest.container.drawer.count = 0;
    dest.container.drawer.clrAndObj.color = RESETC;
    dest.container.drawer.clrAndObj.object = RESETO;

    dest.surface.shelf.count = 0;
    dest.surface.shelf.clrAndObj.color = RESETC;
    dest.surface.shelf.clrAndObj.object = RESETO;

    dest.surface.desktop.count = 0;
    dest.surface.desktop.clrAndObj.color = RESETC;
    dest.surface.desktop.clrAndObj.object = RESETO;

    dest.surface.floor.count = 0;
    dest.surface.floor.clrAndObj.color = RESETC;
    dest.surface.floor.clrAndObj.object = RESETO;

} 



/**
 * Global Destination
 */
//Destination destination; // = NULL;
int main()
{
    char buf[255];
    memset(buf, 0, 255);
    CommandType cmdType = ERRCMD;
    Color colType = ERRC;
    Object objType = ERRO;
    StorageType storeType = ERRSTORAGE;
    StorageType toStoreType;
    StorageType fromStoreType;


    Destination dest;// = NULL;
    //Destination *mainDest = NULL;

    while ((fgets(buf, 255,stdin)) != NULL)
    {
       printf("%s\n", buf);
       char *word;
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
                                populateDest(colType, objType, storeType, dest);
                    
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
                //get the storage type
                word = strtok(NULL, " ");
                storeType = getStorageType(word);
                printf("Store Type: %d\n", storeType);
                if (storeType != ERRSTORAGE)
                {
                    clearDest(storeType, dest);
                }
                else
                {
                    printf("clear cmd error...\n");
                }

            break;
            case MOVE:
                printf("move cmd recevied\n\n");
                //get the storage (place)
                word = strtok(NULL, " ");
                fromStoreType = getStorageType(word);
                if (fromStoreType != ERRSTORAGE)
                {
                     //get the "to" keyword
                     word = strtok(NULL, " ");
                     if (strncmp(word, "to", 2) == 0)
                     {
                         //get the destination storage (place)
                         word = strtok(NULL, " ");
                         toStoreType = getStorageType(word);
                         if (toStoreType != ERRSTORAGE)
                         {
                             moveDestination(fromStoreType, toStoreType, dest);
                         }
                         else
                             printf("Error in move ( to place is invalid)\n");
                     }
                }
                else
                     printf("Error in move (from place is invalid)\n");
                
            break;
            case SHOW:
                printf("show cmd recevied\n\n");
                //get the place 
                word = strtok(NULL, " ");
                storeType = getStorageType(word);
                if (storeType != ERRSTORAGE)
                {
                    show(storeType, dest);
                }
            break;
            case DUMP:
                printf("dump cmd received\n\n");
            break;
            case RESET:
                printf("reset cmd received\n\n");
                reset(dest);
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
