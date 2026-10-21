#pragma force_active on

extern "C" {
bool fn_41_1AE7C(void*);
int fn_41_1AE30(int);
extern float lbl_41_rodata_C90[];
}

class Obj {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float v18();
};

struct Mid {
    char pad0[0xc];
    Obj* obj;
};

struct Actor {
    char pad0[0xd8];
    Mid* mid;
};

struct Enemy {
    char pad0[0x8];
    int unk8;
    char pad1[0x40];
    float unk4C;
};

extern "C" float fn_41_1E6A4(void* a0, void* a1) {
    Enemy* self = (Enemy*)a0;
    Actor* actor = (Actor*)a1;
    float* rd = lbl_41_rodata_C90;
    float f;

    if (fn_41_1AE7C(a0) == 1) {
        return rd[3];
    }
    if (fn_41_1AE30(self->unk8) != 1) {
        return rd[3];
    }
    Obj* o = actor->mid->obj;
    if (self->unk8 == 2 || self->unk8 == 3 || self->unk8 == 4) {
        if (rd[14] == o->v18()) {
            f = rd[0];
        } else {
            f = rd[12];
        }
        return self->unk4C * f;
    }
    return self->unk4C;
}
