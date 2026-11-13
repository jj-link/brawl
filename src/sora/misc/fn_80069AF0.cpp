#include <ms/ms_message.h>

#pragma force_active on

extern "C" unsigned char* fn_8006D40C(unsigned char*, float);

struct Buf {
    char pad[0x4C];
    unsigned int count;
    unsigned char* data;
};

void Message::setWindow(float a, float b, float c, float d) {
    unsigned char tmp[2];
    Buf* p = *(Buf**)((char*)this + 0x1D0);
    p->data[p->count++] = 0x17;

    unsigned char* v = fn_8006D40C(tmp, a);
    p = *(Buf**)((char*)this + 0x1D0);
    p->data[p->count++] = v[0];
    p->data[p->count++] = v[1];

    v = fn_8006D40C(tmp, b);
    p = *(Buf**)((char*)this + 0x1D0);
    p->data[p->count++] = v[0];
    p->data[p->count++] = v[1];

    v = fn_8006D40C(tmp, c);
    p = *(Buf**)((char*)this + 0x1D0);
    p->data[p->count++] = v[0];
    p->data[p->count++] = v[1];

    v = fn_8006D40C(tmp, d);
    p = *(Buf**)((char*)this + 0x1D0);
    p->data[p->count++] = v[0];
    p->data[p->count++] = v[1];
}
