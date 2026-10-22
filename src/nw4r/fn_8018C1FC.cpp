#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    u8 idx;
    u8 flag;
    u8 pad[2];
    u32 ptr;
};

extern "C" u32 fn_80204E5C(u32 owner, u32 size);
extern "C" void fn_80204E6C(u32 owner, u32 ptr);
extern u32 lbl_805A0508;

extern "C" void fn_8018C1FC(Obj* self, u32 arg1) {
    if (self->idx < arg1) {
        if (self->ptr != 0) {
            fn_80204E6C(lbl_805A0508, self->ptr);
            self->ptr = 0;
            self->idx = 0;
            self->flag = 0;
        }
        u32 p = fn_80204E5C(lbl_805A0508, (arg1 << 5) & 0x1FE0);
        self->ptr = p;
        if (p != 0) {
            self->idx = (u8)arg1;
        }
    }
}
