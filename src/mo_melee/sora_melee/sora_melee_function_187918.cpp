#pragma force_active on
extern "C" void fn_27_179BF8(void* self, void* arg);

class IVirt {
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
    virtual int v17(unsigned int id);
};

extern "C" void fn_27_187918(void* self, void* arg) {
    IVirt* sub = *(IVirt**)((char*)*(void**)((char*)arg + 0xd8) + 0x64);
    if (sub->v17(0x1200003b) == 0) {
        fn_27_179BF8(self, arg);
    }
}
