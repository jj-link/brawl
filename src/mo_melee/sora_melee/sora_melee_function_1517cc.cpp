#pragma force_active on
extern "C" void fn_27_613AC(void*, void*);

class VBase {
public:
    virtual ~VBase();
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
    virtual void* get();
};

extern "C" void fn_27_1517CC(void* unused, void* r4)
{
    char* a = *(char**)((char*)r4 + 0xd8);
    VBase* b = *(VBase**)(a + 0x70);
    void* result = b->get();
    fn_27_613AC(r4, result);
}
