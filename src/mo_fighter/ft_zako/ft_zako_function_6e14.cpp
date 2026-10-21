#pragma force_active on

extern "C" const float lbl_126_rodata_4;
extern "C" const float lbl_126_rodata_8;

struct Posture {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void set(bool, int, bool, float, float);
    virtual void pad57();
    virtual void pad58();
    virtual void rate(int, float);
};

struct Work {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void offFlag(int);
};

struct Modules {
    char pad0[8];
    Posture* posture;
    char padC[0x58];
    Work* work;
};

struct Fighter {
    char pad0[0xD8];
    Modules* modules;
};

struct State {
    char pad0[0x60];
    Fighter* fighter;
};

extern "C" void fn_126_6E14(State* state) {
    Fighter* fighter = state->fighter;
    float value = lbl_126_rodata_4;

    fighter->modules->posture->set(true, 0x1CE, true, lbl_126_rodata_8, value);
    fighter->modules->posture->rate(1, value);
    fighter->modules->work->offFlag(0x12000021);
    fighter->modules->work->offFlag(0x12000022);
    fighter->modules->work->offFlag(0x12000023);
    fighter->modules->work->offFlag(0x1200001D);
}
