#include "respond.h"
#include "stdio.h"
#include "Arduino.h"
#include "util.h"
#include "string.h"

respond::respond(unsigned int error_code)
{
    if (error_code > 0) {
        sprintf(msg, "[S#ERR.%d#", error_code);
        char chksum[3];
        sprintf(chksum, "%02d]", util::calc_checksum(msg,8));
        strcat(msg, chksum);
    } else if (error_code == 0) {
        strcpy(msg,"[S#OK#37]");
    }
}

void respond::send()
{
    Serial.println((char*)msg);
    Serial.flush();
}
