#pragma force_active on
class VBase {
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
    virtual int v16();
};

extern "C" bool fn_115_16F38(void* self) {
    void* a = *(void**)((char*)self + 0x60);
    void* b = *(void**)((char*)a + 0xd8);
    void* c = *(void**)((char*)b + 0x70);
    return ((VBase*)c)->v16() != 2;
}
