#pragma force_active on
typedef unsigned char u8;

struct Fn66Object {
    u8 pad0[0x150];
    u8 state;
    u8 pad1[0x15C - 0x151];
    u8 flag;
};

extern "C" void fn_66_12390(Fn66Object* obj) {
    int v = obj->state;
    switch (v) {
    case 0:
    case 1:
        obj->state = 10;
        break;
    case 13:
    case 14:
    case 15:
        obj->flag = 1;
        break;
    }
}
