#pragma force_active on
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

class Timer {
public:
    virtual void v0(int arg);

    u16 m4;
    s16 m6;
};

struct Owner {
    u8 _pad[0x68];
    Timer* m68;
};

extern "C" void fn_802E1814(Owner* self, Timer* arg) {
    if (arg != 0 && arg->m4 != 0) {
        arg->m6 = arg->m6 + 1;
    }
    Timer* t = self->m68;
    if (t != 0 && t->m4 != 0) {
        t->m6 = t->m6 - 1;
        if (t->m6 == 0 && t != 0) {
            t->v0(1);
        }
    }
    self->m68 = arg;
}
