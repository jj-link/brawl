#include <types.h>
#pragma force_active on

struct V2 {
    float x, y;
};

struct V2C {
    float x, y;
    V2C(const V2& p) : x(p.x), y(p.y) {}
};

struct V3 {
    float x, y, z;
    V3(const V3& p) : x(p.x), y(p.y), z(p.z) {}
};

struct V3P {
    float x, y, z;
};

struct Data {
    char pad[0x3C];
    V3 pos;
};

struct Hand {
    char pad0[0x90];
    V2 v;
    char pad98[0xC];
    s32 unkA4;
};

struct Area {
    s32 unk0;
    char pad4[0x1B0];
    s32 unk1B4;
};

struct Obj {
    void* unk0;
    Data* data;
    char pad8[8];
    Hand* unk10;
    Area* unk14;
    s32 unk18;
    s8 unk1C;
    u8 unk1D;
};

extern "C" {
extern float lbl_10_rodata_870;
void fn_10_1C154(void);
void fn_800B6838(void*, const V3P*);
int fn_10_DC38(V2C*);
}

struct MenuObject {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
    virtual void v12();
    virtual void f3c(void*);
};

extern "C" void fn_10_1BF94(Obj* self) {
    if (self->unk14->unk0 == 0) {
        switch (self->unk18) {
        case 0:
            if (self->unk10 != 0) {
                float y = self->unk10->v.y;
                float x = self->unk10->v.x;
                V2 a;
                a.y = y;
                a.x = x;
                V2 b = a;
                V2C c(b);
                V3P offset;
                offset.y = c.y;
                offset.x = c.x;
                offset.z = lbl_10_rodata_870;
                fn_800B6838(self->data, &offset);
            }
            break;
        case 1:
            fn_10_1C154();
            break;
        case 2:
            if (self->unk10->unkA4 != 2) {
                self->unk18 = 0;
            }
            break;
        }

        int hit;
        if (self->unk14->unk0 == 1) {
            hit = 0;
        } else if (self->unk14->unk1B4 == 0) {
            hit = 0;
        } else {
            V3 p(self->data->pos);
            V2 a;
            a.y = p.y;
            a.x = p.x;
            V2 b = a;
            V2C c(b);
            hit = fn_10_DC38(&c) == 1;
        }

        {
            MenuObject* obj = (MenuObject*)self->unk0;
            obj->f3c(*(void**)((char*)self->data + 0x10));
        }

        if (hit != 0 && self->unk1D == 0) {
            MenuObject* obj = (MenuObject*)self->unk0;
            obj->f34(*(void**)((char*)obj + 0xE4), *(void**)((char*)self->data + 0x10));
        }

        self->unk1C = hit;
    }
}
