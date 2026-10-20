#pragma force_active on
extern "C" int fn_27_2EE9C(int value, int a, int b);

struct SoraSub {
    virtual int f0(int b);
    virtual int f1(int b);
    virtual int f2(int b);
    virtual int f3(int b);
};

struct SoraSelf {
    char pad[0x28];
    SoraSub* sub;
};

extern "C" {
    int fn_27_26DD4(SoraSelf* self, int a, int b)
    {
        return fn_27_2EE9C(self->sub->f1(b), a, 0);
    }
}
