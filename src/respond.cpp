#include "respond.h"
#include "stdio.h"
#include "Arduino.h"
#include "util.h"
#include "string.h"

respond::respond(int error_code)
{
    char c[13];
    if (error_code > 0) {
        sprintf(c, "[S#ERR.%d#", error_code);
        char chksum[3];
        sprintf(chksum, "%02d]", util::calc_checksum(c,8));
        strcat(c, chksum);
        strcpy(msg, c);
    } else if (error_code == 0) {
        strcpy(msg,"[S#OK#37]");
    }
}

void respond::send()
{
    Serial.println(msg);
}
