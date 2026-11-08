#pragma force_active on

extern "C" void fn_27_12BAF8(void*, int);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned int id, unsigned int index);

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
    virtual void f13(unsigned int);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void f19(unsigned int);
};

extern "C" void fn_102_7FB8(char* self, int arg) {
    Work* work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->set(-1, 0x10000040);

    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)(self + 0x60), 0xFA6, 0);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->f13(0x11000014);

    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)(self + 0x60), 0xFA8, 0);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->f13(0x11000013);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->f19(0x1200003D);

    work = *(Work**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    work->f19(0x1200003E);

    fn_27_12BAF8(self, arg);
}
