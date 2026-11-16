#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Vec2 {
    float x;
    float y;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int);
    virtual int slot2();
    virtual int slot3();
    virtual Vec3 slot4();
};

struct Inner {
    unsigned char pad0[0xC];
    Object_vptr_0* unkC;
    unsigned char pad10[0xB0];
    Object_vptr_0* unkC0;
};

struct P {
    unsigned char pad0[0xD8];
    Inner* unkD8;
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

extern "C" void fn_27_A6A54(void*, Vec2*, unsigned char, unsigned int, int, void*);
extern "C" void fn_27_A7644(void*, void*);
extern "C" void* fn_27_A7650(void*);

extern "C" void fn_27_A39E4(Self* arg0, Arg* arg1) {
    Self* self = arg0;
    Object_vptr_0* r30;
    void* p;
    int off;
    int i;
    int count = arg1->unk4;
    const Vec3& sp10 = self->unk48->unkD8->unkC->slot4();
    Vec2 sp8;

    sp8.y = sp10.y;
    sp8.x = sp10.x;

    for (i = 0, off = 0; i < count; i++) {
        r30 = self->unk48->unkD8->unkC0;
        p = self->unk30->slot1(i);
        fn_27_A6A54(p, &sp8, self->unk44, arg1->unk0 + off, r30->slot2(),
                    (void*)(self->pad0 + 8));
        off += 0x20;
    }

    if (count > 1) {
        void* r;
        int j;
        r = fn_27_A7650(self->unk30->slot1(0));
        for (j = 1; j < count; j++) {
            fn_27_A7644(self->unk30->slot1(j), r);
        }
    }

    int n = self->unk3C->slot3();
    for (int k = 0; k < n; k++) {
        *(int*)self->unk3C->slot1(k) = -1;
    }
}
