#pragma force_active on
struct VBase {
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
    virtual void v13(void* arg);
};

extern "C" {
void fn_2_1606C(char* self);
}

void fn_2_1606C(char* self) {
    unsigned int off = 0;
    unsigned int i = 0;
    while (i < 6) {
        VBase* obj = *(VBase**)(self + 0x654);
        char* arr = *(char**)(self + 0x64c);
        void* arg = *(void**)(*(char**)(arr + off + 0x18) + 0x10);
        obj->v13(arg);
        i++;
        off += 4;
    }
}
