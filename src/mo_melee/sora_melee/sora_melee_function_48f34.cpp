#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
    u32 fn_27_46C58(u32, void*, u32, u32, u32, u32);
}

struct Sub {
    virtual void v0();
    virtual u32 v1(u32);
};

struct Obj {
    u8 pad[0x20];
    u32 m20;
    u32 m24;
    u8 m28[0x48 - 0x28];
    Sub* m48;
};

extern "C" {
    void fn_27_48F34(Obj* self, u32 a, u32 b) {
        u32 r = self->m48->v1(b);
        u32 x = fn_27_46C58(r, self->m28, self->m20, a, b, self->m24);
        self->m24 += x;
    }
}
