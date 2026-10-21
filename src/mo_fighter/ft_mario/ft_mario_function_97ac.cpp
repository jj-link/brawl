#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f7(int, unsigned int);
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
    virtual void v19();
    virtual void v20();
    virtual void f21(unsigned int);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void f41(int);
};

extern "C" void fn_27_12BAF8(void* self, int arg);

extern "C" void fn_91_97AC(char* self, int arg) {
    Obj* obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f21(0x1200003D);

    obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f7(0, 0x10000040);

    obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f7(0, 0x10000041);

    fn_27_12BAF8(self, arg);

    obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x88);
    obj->f41(0x1A);
}
