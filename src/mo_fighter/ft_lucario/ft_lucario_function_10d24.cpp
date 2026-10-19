#pragma force_active on
extern "C" int fn_118_11410(void* arg);

struct FtCallTarget {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f7(int, unsigned int);
};

extern "C" void fn_118_10D24(void* unused, void* obj) {
    fn_118_11410(obj);
    unsigned char* p = *(unsigned char**)((unsigned char*)obj + 0xd8);
    FtCallTarget* t = *(FtCallTarget**)(p + 0x64);
    t->f7(0, 0x20000001);
}
