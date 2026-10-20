#pragma force_active on
typedef unsigned int u32;

class Callback {
    u32 padding[2];

public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual u32 invoke(void*, u32, int, u32, u32, u32);
};

struct State {
    unsigned char padding0[0x44];
    void* context;
    Callback* callback;
    unsigned char padding1[0x14];
    unsigned char active;
    unsigned char padding2[7];
    u32 value;
};

extern "C" bool fn_27_B86D4(State* self, int mode, u32 a, u32 b, u32 c) {
    if (mode != 2) {
        if (self->callback->invoke(self->context, self->value, mode, a, b, c) == 1) {
            self->active = 1;
            return true;
        }
    }
    return false;
}
