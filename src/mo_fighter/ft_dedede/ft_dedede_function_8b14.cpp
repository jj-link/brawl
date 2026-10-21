extern "C" void fn_27_12BAF8(void*, int);

#pragma force_active on
struct DededeFace {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f5(int, unsigned int);
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
    virtual void f19(unsigned int);
};

extern "C" void fn_117_8B14(char* self, int arg1) {
    DededeFace* obj;

    obj = *(DededeFace**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f19(0x1200003D);

    obj = *(DededeFace**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f5(0, 0x10000042);

    obj = *(DededeFace**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f5(-1, 0x10000043);

    obj = *(DededeFace**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f5(-1, 0x10000044);

    fn_27_12BAF8(self, arg1);
}
