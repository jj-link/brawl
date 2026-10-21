#pragma force_active on
extern "C" {

void fn_27_13138C(void*, void*, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

struct Vt {
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
    virtual void m13(unsigned int);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void m18(unsigned int);
};

void fn_103_9200(void* self, void* arg1, int kind) {
    fn_27_13138C(self, arg1, kind);
    if (kind == 0x11b) {
        unsigned char* sp = (unsigned char*)self;
        void* a1 = *(void**)(sp + 0x60);
        void* b1 = *(void**)((unsigned char*)a1 + 0xd8);
        void* c = *(void**)((unsigned char*)b1 + 0x64);
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a1, 0xfbc, 0);
        ((Vt*)c)->m13(0x11000000);
        void* a2 = *(void**)(sp + 0x60);
        void* b2 = *(void**)((unsigned char*)a2 + 0xd8);
        c = *(void**)((unsigned char*)b2 + 0x64);
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a2, 0xfbb, 0);
        ((Vt*)c)->m13(0x11000001);
        void* d = *(void**)(sp + 0x60);
        d = *(void**)((unsigned char*)d + 0xd8);
        d = *(void**)((unsigned char*)d + 0x64);
        ((Vt*)d)->m18(0x12000003);
    }
}

}
