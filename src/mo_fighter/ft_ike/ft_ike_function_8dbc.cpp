#pragma force_active on
struct Obj {
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
    virtual void setValue(float value, unsigned int index);
};

extern "C" void fn_119_8DBC(char* self, float* vec) {
    Obj* obj = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
    obj->setValue(vec[0], 0x2100000C);
    obj = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
    obj->setValue(vec[1], 0x2100000D);
    obj = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
    obj->setValue(vec[2], 0x2100000E);
}
