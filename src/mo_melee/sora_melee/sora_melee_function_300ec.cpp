#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Sub {
    u8 pad[0x6c];
    union {
        struct {
            u32 hi : 8;
            u32 lo : 24;
        } w6c;
        struct {
            u8 x;
            unsigned char b6d : 8;
            u16 y;
        } s;
    };
};

struct Obj {
    u32 pad;
    Sub* sub;
};

extern "C" void fn_27_300EC(Obj* self, u32 flag) {
    self->sub->s.b6d = flag;
    self->sub->w6c.hi = 1;
}
