#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    float x, y;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int* slot1(int);
    virtual int slot2();
    virtual int slot3();
    virtual Vec3 slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
};

struct Q {
    unsigned char pad0[0xC];
    Object_vptr_0* unkC;
    unsigned char pad10[0xB0];
    Object_vptr_0* unkC0;
};

struct P {
    unsigned char pad0[0xD8];
    Q* unkD8;
};

struct Self {
    unsigned char pad0[0x30];
    Object_vptr_0* unk30;
    unsigned char pad34[8];
    Object_vptr_0* unk3C;
    unsigned char pad40[4];
    unsigned char unk44;
    unsigned char pad45[3];
    P* unk48;
};

struct Arg {
    unsigned int unk0;
    unsigned int unk4;
};

extern "C" void fn_27_A6948(void*);
extern "C" void fn_27_A6978(void*, int);
extern "C" void fn_27_A6A54(void*, Vec2*, unsigned char, unsigned int, int, void*);
extern "C" void fn_27_A7644(void*, void*);
extern "C" void* fn_27_A7650(void*);

extern "C" void fn_27_A3B6C(Self* arg0, Arg* arg1) {
    Self* self = arg0;
    int j;
    void* r31;
    Object_vptr_0* r30;
    int* p;
    int off;
    unsigned int i;
    unsigned char sp1C[0x24];
    const Vec3& sp10 = self->unk48->unkD8->unkC->slot4();
    Vec2 sp8;

    for (i = 0, off = 0; i < arg1->unk4; i++) {
        fn_27_A6948(sp1C);
        self->unk30->slot10(sp1C);
        fn_27_A6978(sp1C, -1);
        r30 = self->unk48->unkD8->unkC0;
        float y = sp10.y;
        sp8.x = sp10.x;
        sp8.y = y;
        int index = self->unk30->slot3() - 1;
        p = self->unk30->slot1(index);
        fn_27_A6A54(p, &sp8, self->unk44, arg1->unk0 + off,
                     r30->slot2(), (void*)(self->pad0 + 8));
        off += 0x20;
    }

    if (self->unk30->slot3() > 1) {
        void* t = self->unk30->slot1(0);
        r31 = fn_27_A7650(t);
        for (j = 1; j < self->unk30->slot3(); j++) {
            fn_27_A7644(self->unk30->slot1(j), r31);
        }
    }

    int n = self->unk3C->slot3();
    for (int k = 0; k < n; k++) {
        *self->unk3C->slot1(k) = -1;
    }
}
