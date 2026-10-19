#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Fn76Obj {
    char pad[0x168];
    u8* flag;
};

struct Fn76Msg {
    u32 w0;
    u32 w1;
    u32 w2;
};

extern "C" void fn_76_19CC(Fn76Obj* obj, Fn76Msg* msg) {
    u8* p = obj->flag;
    if (p == 0) {
        return;
    }
    if (((int)((msg->w2 << 8) & 0xFF800000) >> 24) != 2) {
        return;
    }
    *p = 1;
}
