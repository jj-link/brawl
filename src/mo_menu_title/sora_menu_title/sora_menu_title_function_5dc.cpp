#pragma force_active on
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
    virtual void v13(void* a, void* b);
};

extern "C" void fn_24_5DC(char* self) {
    char* a = *(char**)(self + 0x1c4);
    char* b = *(char**)(self + 0x1c8);
    Obj* o = *(Obj**)(a + 0x48);
    o->v13(*(void**)((char*)o + 0xe4), *(void**)(b + 0xc));

    a = *(char**)(self + 0x1c4);
    b = *(char**)(self + 0x1cc);
    o = *(Obj**)(a + 0x48);
    o->v13(*(void**)((char*)o + 0xe4), *(void**)(b + 0xc));
}
