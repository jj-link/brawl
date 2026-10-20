#include <types.h>
#pragma force_active on

struct ftManager;
extern ftManager* g_ftManager;

extern "C" int getPlayerNo__9ftManagerFi(ftManager*, int);
extern "C" int fn_27_27D2AC(void*, int);

struct Target {
    u8 padding[0x3c];

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
    virtual void call(int, int);
};

struct State {
    u8 padding[0x2c];
    Target* target;
    u8 padding30[4];
    u8 enabled : 1;
    u8 flags : 7;
};

extern "C" void fn_27_2D8FBC(State* self, int entryId, int value) {
    if (self->enabled && self->target) {
        int index = fn_27_27D2AC(
            self, getPlayerNo__9ftManagerFi(g_ftManager, entryId));
        self->target->call(index, value);
    }
}
