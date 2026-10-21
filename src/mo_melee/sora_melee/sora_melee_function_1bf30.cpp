#pragma force_active on
typedef short s16;
typedef int s32;
typedef float f32;

extern "C" const f32 lbl_27_rodata_344;

class Obj4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void*, s16*, f32);
};

struct Base8 {
    char pad[8];
};

class Hdr8 : public Base8 {
public:
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
    virtual void v11();
    virtual void v12();
    virtual f32 get();
};

class Low {
public:
    char pad0[0x6c];
    Obj4* m_6c;
    char pad1[0xb8 - 0x70];
    Hdr8* m_b8;
};

class Mid {
public:
    char pad[0xd8];
    Low* m_d8;
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual f32 v6();

    char pad[0x168 - 4];
    Mid* m_168;
};

extern "C" void fn_27_1BF30(Self* self, s16* arg1, s32 arg2) {
    f32 f = lbl_27_rodata_344;
    if (arg2 == 0) {
        f32 t = self->m_168->m_d8->m_b8->get();
        f32 u = self->v6();
        f = u * t;
    }

    s16 sp8 = *arg1;
    Mid* mid = self->m_168;
    mid->m_d8->m_6c->v2(mid, &sp8, f);
}
