#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

struct Elem {
    u8 pad[9];
    s8 flag;
    u8 pad2[2];
};

struct Owner {
    u8 pad[8];
    Elem* elems;
    s32 index;
};

extern "C" {
bool fn_27_1B1A40(Owner* o)
{
    return o->elems[o->index].flag >= 0;
}
}
