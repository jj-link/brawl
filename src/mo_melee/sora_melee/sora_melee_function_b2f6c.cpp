#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_B16C8(void*);

struct Callback {
    virtual ~Callback();
    virtual void* f0();
};

struct This {
    char pad[0x18];
    Callback* callback;
};

extern "C" void fn_27_B2F6C(This* self) {
    u32* work = (u32*)fn_27_B16C8(self->callback->f0());
    work[2] &= ~0x8000u;
}
