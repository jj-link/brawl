#pragma force_active on
extern "C" {
void fn_96_DC08(void* self);
void fn_96_1D68C(void* obj, int value);
}

struct VObj {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual int v4(unsigned int id);
};

extern "C" void fn_96_DCD8(void* self, int value) {
    void* a = *(void**)((char*)self + 0x60);
    void* b = *(void**)((char*)a + 0xd8);
    VObj* c = *(VObj**)((char*)b + 0x64);
    int r = c->v4(0x10000048);
    if (value == r) {
        fn_96_DC08(self);
    }
    fn_96_1D68C((char*)self + 0x1B72C, value);
}
