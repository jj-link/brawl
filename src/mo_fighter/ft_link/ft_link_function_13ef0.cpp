#pragma force_active on
extern "C" void fn_27_1DACB8(void* fighter);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int);
};

extern "C" void fn_93_13EF0(char* fighter) {
    Obj* obj = *(Obj**)(*(char**)(*(char**)(fighter + 0x60) + 0xD8) + 0x64);
    obj->v18(0x12000004);
    fn_27_1DACB8(fighter);
}
