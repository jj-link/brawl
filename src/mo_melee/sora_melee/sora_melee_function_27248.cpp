#include <types.h>
#pragma force_active on

extern "C" void fn_801357F0(float* dst, const float* a, const float* b, float c);

struct Res {
    s32 a;
    float* dst;
};

class Obj {
public:
    virtual void slot0();
    virtual Res* slot1(s32 a);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

struct Mid {
    s32 pad0[3];
    Obj* c;
};

struct Top {
    char pad0[0xd8];
    Mid* d8;
};

struct Entry {
    float x;
    float y;
    float z;
    float w;
};

struct Inner {
    Entry* entries;
    s32 count;
};

struct Outer {
    char pad0[0x28];
    Obj* unk28;
    char pad1[0x3c - 0x2c];
    Inner* unk3C;
    float unk40;
    char pad2[0x54 - 0x44];
    Top* unk54;
};

extern "C" void fn_27_27248(Outer* self, u32 index, s32 arg2) {
    float v[4];
    {
        if (self->unk3C == 0 || self->unk3C->entries == 0) return;
        Entry* entries = self->unk3C->entries;
        if (index < (u32)self->unk3C->count) {
            Entry* e = &entries[index];
            float s = self->unk54->d8->c->slot22();
            float t1 = e->y * s;
            float t0 = e->x * s;
            v[3] = t1;
            v[2] = t0;
            float t3 = e->w * s;
            float t2 = e->z * s;
            v[1] = t3;
            v[0] = t2;
            Obj* o = self->unk28;
            Res* r = o->slot1(arg2);
            fn_801357F0(r->dst, &v[2], &v[0], v[0] * self->unk40);
        }
    }
}
