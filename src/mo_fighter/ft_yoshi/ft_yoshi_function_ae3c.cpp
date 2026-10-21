#pragma force_active on
extern "C" {
void fn_27_1FF0C(void*);
void fn_27_1FFCC(const void*);
}

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
    virtual int v17(unsigned int);
    virtual void v18();
    virtual void v19(unsigned int);
};

extern "C" void fn_95_AE3C(void* self) {
    char* s = (char*)self;
    char* ft = *(char**)(s + 0x60);
    Obj* obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
    if (obj->v17(0x1200003d)) {
        fn_27_1FF0C(s + 0x22288);
        fn_27_1FFCC(s + 0x22288);
        obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
        obj->v19(0x1200003d);
    }
}
