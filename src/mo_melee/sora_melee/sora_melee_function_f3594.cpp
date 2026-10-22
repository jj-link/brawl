#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual int* get(int index);
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int v14();
};

class Outer {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    u8 pad[0xC];
    Inner sub;
};

extern "C" int fn_27_F3594(Outer* self) {
    int temp_r31;
    int var_r30;
    int n;

    if ((u32)self->sub.v14() == 1U) {
        return 0x7FFF;
    }
    if ((u32)self->s5() == 1U) {
        return 0;
    }
    n = self->sub.size() - 1;
    if (self->sub.get(n)[1] < 0x7FFF) {
        n = self->sub.size() - 1;
        return self->sub.get(n)[1] + 1;
    }
    var_r30 = self->sub.size() - 1;
    while (var_r30 >= 0) {
        if (var_r30 == 0) {
            if (self->sub.get(var_r30)[1] == 0) {
                return -1;
            }
            return self->sub.get(var_r30)[1] - 1;
        }
        temp_r31 = self->sub.get(var_r30 - 1)[1];
        if (self->sub.get(var_r30)[1] - 1 > temp_r31) {
            return self->sub.get(var_r30)[1] - 1;
        }
        var_r30 -= 1;
    }
    return -1;
}
