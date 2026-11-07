#pragma force_active on

extern "C" const float lbl_27_rodata_78;
extern "C" const float lbl_27_rodata_7C;

struct Msg {
    int id;
    float a;
    float b;
    unsigned char c[4];
};

class Mod {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4(int);
    virtual void s5(int);
    virtual void s6(int, int);
    virtual void s7(int);
    virtual void s8();
    virtual void s9();
    virtual void s10(int);
    virtual void s11(int);
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19(int, int);
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30(Msg*);
};

struct Mod8Base { char pad[8]; };
class Mod8 : public Mod8Base {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19(int, int);
};

struct Accesser {
    char pad0[8];
    Mod* m08;
    char pad1[4];
    Mod8* m10;
    Mod* m14;
    char pad2[8];
    Mod* m20;
    char pad3[0x34];
    Mod* m58;
    char pad4[4];
    Mod* m60;
    char pad5[0x2c];
    Mod* m90;
    char pad6[0x10];
    Mod* mA4;
    char pad7[8];
    Mod8* mB0;
};

struct Holder {
    char pad[0xd8];
    Accesser* acc;
};

struct OwnerBase { char pad[0x3c]; };
class Owner : public OwnerBase {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual int accept(signed char);

    char pad40[0x20];
    Holder* holder;
};

class Actor {
public:
    virtual void v0();
    virtual signed char category();
    virtual signed char state();
};

extern "C" int fn_27_6270(Owner* self, Actor* arg) {
    if (self->accept(arg->category()) == 0) {
        return 0;
    }
    if (arg->state() <= -1 || arg->state() >= 5) {
        return 0;
    }
    switch (arg->state()) {
    case 1:
        self->v43();
        return 1;
    case 2: {
        self->holder->acc->m58->s7(0);
        self->holder->acc->m20->s19(2, 0);
        self->holder->acc->m90->s10(0);
        self->holder->acc->m60->s11(0);
        self->holder->acc->m14->s6(5, 0);
        self->holder->acc->m10->s19(0, 0);
        Msg msg;
        msg.id = -1;
        msg.a = lbl_27_rodata_7C;
        msg.b = lbl_27_rodata_78;
        msg.c[0] = 0;
        msg.c[1] = 0;
        msg.c[2] = 0;
        msg.c[3] = 0;
        self->holder->acc->m08->s30(&msg);
        self->holder->acc->mB0->s5(0);
        self->holder->acc->mA4->s4(0);
        return 1;
    }
    case 3:
        self->holder->acc->m58->s7(1);
        self->holder->acc->m20->s19(0, 0);
        self->holder->acc->m90->s10(1);
        self->holder->acc->m60->s11(1);
        self->holder->acc->mB0->s5(1);
        self->holder->acc->mA4->s4(1);
        return 1;
    case 4:
        self->holder->acc->m14->s6(2, 0);
        self->holder->acc->m10->s19(5, 0);
        return 1;
    default:
        return 0;
    }
}
