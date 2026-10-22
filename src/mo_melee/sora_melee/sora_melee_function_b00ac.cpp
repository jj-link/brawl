#pragma force_active on

class Seq {
public:
    virtual void a0();
    virtual void a1();
    virtual int* s4(int index);
    virtual int s5();
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual unsigned int s16();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int s7();
    char pad[0xC];
    Seq sub;
};

extern "C" int fn_27_B00AC(Self* self) {
    int t;
    int i;
    if (self->sub.s16() == 1) {
        return 0x7FFF;
    }
    if (self->s7() == 1) {
        return 0;
    }
    int n = self->sub.s5() - 1;
    if (self->sub.s4(n)[1] < 0x7FFF) {
        n = self->sub.s5() - 1;
        return self->sub.s4(n)[1] + 1;
    }
    i = self->sub.s5() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.s4(i)[1] == 0) {
                return -1;
            }
            return self->sub.s4(i)[1] - 1;
        }
        t = self->sub.s4(i - 1)[1];
        if (self->sub.s4(i)[1] - 1 > t) {
            return self->sub.s4(i)[1] - 1;
        }
        i--;
    }
    return -1;
}
