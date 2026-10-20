#pragma force_active on
extern "C" {
    void fn_27_429D0(void* a, void* b, void* c);
}

class fn27Sub {
public:
    virtual void vf0();
    virtual void* vf1(void* p);
};

class fn27Self {
public:
    char pad0[0x30];
    void* m30;
    char pad1[0x58 - 0x34];
    fn27Sub* m58;
};

extern "C" void fn_27_4513C(fn27Self* self, void* a, void* b) {
    fn_27_429D0(self->m58->vf1(b), self->m30, a);
}
