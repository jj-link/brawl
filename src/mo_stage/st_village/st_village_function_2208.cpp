#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0x158];
    u8 *ptr158;
    u8 flag15c;
};

extern "C" int fn_70_2208(Obj *obj) {
    u8 *p = obj->ptr158;
    if (p == 0) {
        return 0;
    }
    u8 f = obj->flag15c;
    if (f == 0) {
        return 1;
    }
    return (f & (1 << *p)) != 0;
}
