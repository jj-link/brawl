#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Motion {
    u8 pad[8];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual float getRate();
    virtual void unused42();
    virtual u32 isEnd(u8*);
};

struct Modules {
    u8 pad[0x38];
    Motion* motion;
};

struct soModuleAccesser {
    u8 pad[0xD8];
    Modules* modules;
};

struct State {
    u8 pad0[0x10];
    soModuleAccesser* accessor;
    u8 pad14[0x14];
    float time;
    u8 pad2C[5];
    u8 ended;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" bool fn_27_669B0(State* self) {
    Motion* motion = self->accessor->modules->motion;
    self->time += motion->getRate();

    if (self->time >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                          self->accessor, 0x7F2, 0))
        return false;

    u8 ended;
    motion = self->accessor->modules->motion;
    if (motion->isEnd(&ended) == 1) {
        if (ended == 1)
            self->ended = 1;
        return false;
    }

    return true;
}
