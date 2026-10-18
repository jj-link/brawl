#pragma force_active on
class Sub {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
};

extern "C" int fn_123_B564(char* self) {
    Sub* s = (Sub*)(self + 0xD028);
    return s->f2();
}
