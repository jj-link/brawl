#pragma force_active on

class Inner {
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
    virtual void invoke(int a, int b);
    virtual void v12();
    virtual void v15(int a);
    char pad[0xe4 - 4];
    int m_e4;
};

class Obj18 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(void* a, float b);
    virtual void v9();
};

struct Obj14 {
    char pad[0x18];
    Obj18* p18;
};

struct Obj67c {
    char pad[0x14];
    Obj14* p14;
};

struct MenuBase {
    char pad0[0x654];
    Inner* m654;
    char pad658[0x10];
};

class Self : public MenuBase {
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
    virtual void v18();
    virtual void v19(int a);
    char pad66c[0x4];
    int m670;
    char pad674[0x8];
    Obj67c* m67c;
    void* m680;
    char pad684[0x8];
    int m68c;
    int m690;
};

extern "C" {
extern const float lbl_2_rodata_EBC;
extern const unsigned char lbl_2_rodata_EC4[];
extern char lbl_2_data_3358[];
extern char lbl_2_data_33D0[];

void fn_800B330C(void*, void*, int);
void fn_2_29B44(void*, int);

void fn_2_299B0(Self* self, int arg) {
    int state = arg;

    self->m654->invoke(self->m654->m_e4, self->m68c);
    self->m654->invoke(self->m654->m_e4, self->m690);
    self->m67c->p14->p18->v10(self->m67c, lbl_2_rodata_EBC);
    fn_800B330C(self->m680, lbl_2_data_33D0, 0);

    switch (state) {
    case 0:
        state = 2;
        break;
    case 1:
        state = 4;
        break;
    case 2:
        state = 2;
        break;
    }

    if (state != self->m670) {
        self->m670 = state;
        if (state == 0) {
            self->m654->v15(self->m68c);
            self->m654->v15(self->m690);
        } else {
            if (state == 1) {
                self->v16();
            }
            fn_800B330C(self->m67c, lbl_2_data_3358 + lbl_2_rodata_EC4[state] * 0x14, 0);
        }
    }

    fn_2_29B44(self, 0);
    self->v19(1);
}
}
