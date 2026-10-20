#pragma force_active on
struct Secondary {
    unsigned char pad[0x40];
    unsigned int flags;
};

struct Object {
    unsigned char pad0[0x50];
    unsigned int flags;
    unsigned char pad54[0x68];
    Secondary* secondary;
    unsigned char padC0[0xFA];
    unsigned char state;
};

extern "C" unsigned int fn_27_20B568(Object* obj) {
    unsigned int flags = obj->flags;
    if (((flags & 1) == 0 && (obj->secondary->flags & 0x20000) == 0)
        || (unsigned char)(obj->state + 0xFA) <= 1)
        return 1;
    return ((flags >> 1) & 1) ^ 1;
}
