#pragma force_active on

class V {
public:
    virtual void vf0();
    virtual void vf1();
};

struct Pad0 {
    unsigned char x[0x664];
};

class Sub : public Pad0, public V {
public:
    virtual void vf2();
};

extern "C" void fn_18_FA0(char* self) {
    int idx = *(int*)(self + 0x278);
    if (idx != 5) {
        Sub* sub = *(Sub**)(self + 0x268 + idx * 4);
        sub->vf2();
        *(int*)(self + 0x278) = 5;
    }
    int idx2 = *(int*)(self + 0x27C);
    if (idx2 != 5) {
        Sub* sub = *(Sub**)(self + 0x268 + idx2 * 4);
        sub->vf2();
        *(int*)(self + 0x27C) = 5;
    }
    *(unsigned char*)(self + 0x288) = 1;
}
