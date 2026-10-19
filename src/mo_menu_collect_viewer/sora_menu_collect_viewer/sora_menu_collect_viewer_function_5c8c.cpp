#pragma force_active on
struct Input {
    char pad[0x1B54];
    unsigned int flags;
};

struct ViewerBase {
    char pad[0x3C];

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
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void move(int, int);
};

struct Viewer : ViewerBase {
    char pad1[0x168];
    unsigned int flags;
    Input* input;
};

extern "C" int fn_6_5C8C(Viewer* self, int enabled, int step) {
    int direction = 0;

    if (enabled) {
        unsigned int flags = self->input->flags;
        if (flags & 1)
            direction = -1;
        else if (flags & 2)
            direction = 1;
    }

    if (direction == 0) {
        unsigned int flags = self->flags;
        if (flags & 0x80)
            direction = -step;
        else if (flags & 0x100)
            direction = step;
        else if (flags & 0x20)
            direction = -1;
        else if (flags & 0x40)
            direction = 1;
        else
            return 0;
    }

    self->move(enabled, direction);
    return direction;
}
