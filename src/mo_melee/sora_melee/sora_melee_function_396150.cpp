#pragma force_active on
class VObj {
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
    virtual int v17(unsigned int arg);
};

extern "C" void fn_27_3962BC(void* a, void* b);

extern "C" void fn_27_396150(void* self, void* arg) {
    char* p = *(char**)((char*)arg + 0xd8);
    VObj* obj = *(VObj**)(p + 0x64);
    if (obj->v17(0x22000012)) {
        fn_27_3962BC(self, arg);
    }
}
