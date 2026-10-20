#pragma force_active on
typedef unsigned int u32;

struct ObjectData {
    char* data;
    u32 unused[2];
};

struct Object : ObjectData {
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
    virtual void callback(u32, u32);
};

extern "C" u32 fn_27_1D5434(void*, u32, u32);

extern "C" void fn_27_1D7104(Object* self, u32 value) {
    if (value == 1) {
        if (fn_27_1D5434(self->data + 0x9e8, 0x12, 0) == 1) {
            self->callback(0x12, 0);
        }
        if (fn_27_1D5434(self->data + 0x9e8, 0x13, 0) == 1) {
            self->callback(0x13, 0);
        }
    }
}
