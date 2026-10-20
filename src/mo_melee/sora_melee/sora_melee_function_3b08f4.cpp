#pragma force_active on
extern "C" void fn_27_5A78(void* p);

class VObj {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(unsigned int id);
};

extern "C" void fn_27_3B08F4(char* self) {
    char* a = *(char**)(self + 0x60);
    char* b = *(char**)(a + 0xd8);
    VObj* c = *(VObj**)(b + 0x70);
    if (c->v18() == 0) {
        char* a2 = *(char**)(self + 0x60);
        char* b2 = *(char**)(a2 + 0xd8);
        VObj* c2 = *(VObj**)(b2 + 0x64);
        c2->v21(0x22000004);
    }
    fn_27_5A78(self);
}
