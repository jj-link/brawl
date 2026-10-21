#pragma force_active on

extern "C" void fn_27_12BAF8(void*, int);

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void clear(unsigned int);
};

extern "C" void fn_115_87E8(char* self, int arg) {
    Work* work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->clear(0x1200003D);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->set(0, 0x10000040);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->clear(0x1200003E);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->clear(0x1200003F);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->set(0, 0x20000002);

    fn_27_12BAF8(self, arg);
}
