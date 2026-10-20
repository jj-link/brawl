#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Inner {
    u8 pad[0x40];
    u32 flags;
};

struct Outer {
    u8 pad[0xbc];
    Inner* inner;
    u8 flag;
};

extern "C" bool fn_27_20C540(Outer* o) {
    if (o->flag == 0) {
        if (o->inner->flags & 0x20000) {
            return true;
        }
    }
    return false;
}
