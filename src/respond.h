#ifndef RESPOND_H
#define RESPOND_H

class respond
{
public:
    respond(int error_code);
    void send();
    char msg[15];
private:
    respond();
};

#endif // RESPOND_H
