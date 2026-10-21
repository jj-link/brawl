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
    virtual void v11();
    virtual void v12();
    virtual void v13(unsigned int, float);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int);
    virtual void v19(unsigned int);
};

extern "C" {
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];
void fn_107_141A0(void*, void*);
}

extern "C" void fn_107_13214(void* self, void* accesser) {
    char* ft = (char*)accesser;
    float f = *(float*)((char*)*(char**)((char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12) + 0xb8) + 0x20);
    Obj* obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
    obj->v13(0x21000006, f);
    obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
    obj->v19(0x22000010);
    obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
    obj->v19(0x22000011);
    obj = *(Obj**)(*(char**)(ft + 0xd8) + 0x64);
    obj->v18(0x22000012);
    fn_107_141A0(self, accesser);
}
