#pragma force_active on
extern "C" void fn_801830B0();

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

extern "C" void fn_80185E14(void* self, int arg1) {
    char* base = (char*)self;
    fn_801830B0();
    if ((*((unsigned char*)base + 0xB7) & 1) || !(arg1 & 1)) {
        for (int i = 0; i < *((unsigned char*)(base + 0x100)); i++) {
            void* ptr = *(void**)((char*)*(void**)(base + 0xFC) + i * 8 + 4);
            ((Obj*)ptr)->v5();
        }
    }
}