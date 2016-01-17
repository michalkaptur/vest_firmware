#include "respond.h"
#include "stdio.h"
#include "Arduino.h"

respond::respond(int error_code)
{
    //TODO: checksums, extract from parser
    char c[13];
    if (error_code > 0) {
        sprintf(c, "/S#ERR.%d#00\\", error_code);
        Serial.println(c);
    } else if (error_code == 0) {
        Serial.println("/S#OK#00\\");
    }
}
