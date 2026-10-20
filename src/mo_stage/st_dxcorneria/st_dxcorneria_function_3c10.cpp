#pragma force_active on
extern "C" int randi__Fl(long);

struct Target {
    char padding[0x3C];

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
    virtual void select(unsigned int);
};

struct State {
    char padding[0x1040];
    Target* target;
    unsigned int group;
    bool active;
};

extern "C" bool fn_82_3C10(State* self) {
    unsigned int index = randi__Fl(5);
    if (index >= 4)
        index = 4;

    unsigned int base = self->group * 5;
    unsigned int selection = base + index;
    Target* target = self->target;

    if (target)
        target->select(selection);

    self->active = true;
    return true;
}
