#pragma force_active on
class VBase {
public:
    virtual int f0() = 0;
    virtual int f1() = 0;
    virtual int f2() = 0;
    virtual int f3() = 0;
    virtual int f4() = 0;
    virtual int f5() = 0;
    virtual int f6() = 0;
    virtual int f7() = 0;
    virtual int f8() = 0;
    virtual int f9() = 0;
    virtual int f10() = 0;
    virtual int f11() = 0;
    virtual int f12() = 0;
    virtual int f13() = 0;
    virtual int f14() = 0;
    virtual int f15() = 0;
};

extern "C" {
int fn_27_17952C(void* unused, char* b) {
    char* p = *(char**)(b + 0xd8);
    VBase* obj = *(VBase**)(p + 0x3c);
    return obj->f13();
}
}
