#include <types.h>
#pragma force_active on

struct FnDst {
    unsigned int a;
    unsigned int b;
    short c;
    short d;
};

class Class_19FD0 {
public:
    virtual void fn_27_DCA5C();
    virtual void fn_27_DC3F0();
    virtual void* fn_27_DC400(int);
    virtual void fn_27_D32CC();
    virtual void fn_27_86AD0();
    virtual void fn_27_D320C();
    virtual void fn_27_DC504();
    virtual void fn_27_DC6B4();
    virtual void fn_27_DCA14();
    virtual void fn_27_DC410();
    virtual void fn_27_DC5C0();
    virtual void fn_27_DC770(int, FnDst*);
    virtual void fn_27_DC888();
    virtual void fn_27_D32C4();
    virtual unsigned int fn_27_D32B8();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
    virtual void slot5();
    virtual unsigned int slot6(int);
    char pad04[0xC];
    Class_19FD0 inner;
    char pad14[0x20];
    unsigned char flag;

    inline int find(int limit) {
        if (limit <= -1) return slot4();
        int n = slot4();
        for (int i = 0; i < n; i++) {
            short val = *(short*)((unsigned char*)inner.fn_27_DC400(i) + 0xA);
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};

extern "C" int fn_27_292CA0(soNullable*);
extern "C" void fn_27_FE1C4(FnDst*, const int*, int, const short*, int);

extern "C" int fn_27_292488(soNullable* self, const int* arg1, int arg2, const short* arg3, int arg4) {
    if (self->inner.fn_27_D32B8() == 1U) return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->slot6(arg2) == 1U) return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        int result = fn_27_292CA0(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    int idx = self->find(arg4);
    if (idx < 0) return -1;
    short sp8 = *arg3;
    FnDst spC;
    fn_27_FE1C4(&spC, arg1, arg2, &sp8, arg4);
    self->inner.fn_27_DC770(idx, &spC);
    return arg2;
}
