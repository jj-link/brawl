#pragma force_active on
struct Data {
    char padding[0x184];
    int entries[3];
};

struct Base {
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
    virtual void enable(int);
    virtual void disable(int);
};

struct Viewer : Base {
    char padding1[0x16C];
    Data* data;
};

extern "C" void fn_6_6E28(Viewer* self, int enabled, int second)
{
    int index = 2;
    if (second == 0)
        index = 1;

    if (enabled)
        self->enable(self->data->entries[index]);
    else
        self->disable(self->data->entries[index]);
}
