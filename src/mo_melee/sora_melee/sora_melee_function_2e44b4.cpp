#pragma force_active on
extern "C" void fn_27_1D8FC8(void*, int);

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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int, int, int);
};

extern "C" void fn_27_2E44B4(void* self, int arg) {
    Obj* obj = *(Obj**)(*(char**)(*(char**)((char*)self + 0x60) + 0xD8) + 0x88);
    obj->v24(0, 1, 1);
    fn_27_1D8FC8(self, arg);
}
