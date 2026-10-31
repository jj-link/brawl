#pragma force_active on

struct Entry {
    char pad[0xA];
    short unkA;
};

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int idx);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vA();
    virtual void set(int idx, void* data);
    virtual void vB();
    virtual void vC();
    virtual unsigned int full();
};

struct FnData {
    int unk0;
    int unk4;
    short unk8;
    short unkA;
};

struct Arg0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int check(int arg);
    char pad0[0xC];
    SubObj sub;
    char pad1[0x74];
    unsigned char flag;

    inline int find(int c) {
        if (c <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            short v = sub.get(i)->unkA;
            if (v <= -1) return i;
            if (v > c) return i;
        }
        return n;
    }
};

extern "C" void fn_27_1CF4D8(
    FnData* dst,
    const unsigned int* src,
    int val,
    short* half,
    int half2
);
extern "C" int fn_27_294088(Arg0* self);

extern "C" int fn_27_293870(
    Arg0* self,
    const unsigned int* arg1,
    int arg2,
    short* arg3,
    int arg4
) {
    short sp8;
    FnData spC;

    if (self->sub.full() == 1U)
        return -1;

    if (self->flag == 0 || arg2 > -1) {
        if (self->check(arg2) == 1U)
            return -1;
    }

    if (self->flag == 0 && arg2 <= -1) {
        arg2 = fn_27_294088(self);
        if (arg2 <= -1)
            return -1;
    }

    int idx = self->find(arg4);
    if (idx < 0)
        return -1;

    sp8 = *arg3;
    fn_27_1CF4D8(&spC, arg1, arg2, &sp8, arg4);
    self->sub.set(idx, &spC);
    return arg2;
}
