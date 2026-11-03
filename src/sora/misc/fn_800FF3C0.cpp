#pragma force_active on
extern "C" {
void fn_800FECD4(void*, int, float);
int fn_800B5854(void*, int, int, int, int);
}

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
    virtual void v11(void* a, void* b);
    virtual void v12();
    virtual void v13(void* a);
};

extern "C" void fn_800FF3C0(void* self) {
    char* s = (char*)self;
    VObj* o;

    fn_800FECD4(self, 0, *(float*)(s + 0x118));
    fn_800B5854(*(void**)(s + 0x4), 1, 1, 1, 0);
    o = *(VObj**)s;
    o->v13(*(void**)(s + 0xF0));
    o = *(VObj**)s;
    o->v11(*(void**)((char*)o + 0xE4), *(void**)(s + 0xF0));

    fn_800FECD4(self, 1, *(float*)(s + 0x11C));
    fn_800B5854(*(void**)(s + 0x24), 2, 1, 1, 0);
    o = *(VObj**)s;
    o->v13(*(void**)(s + 0xF4));
    o = *(VObj**)s;
    o->v11(*(void**)((char*)o + 0xE4), *(void**)(s + 0xF4));

    fn_800FECD4(self, 2, *(float*)(s + 0x120));
    fn_800B5854(*(void**)(s + 0x44), 3, 1, 1, 0);
    o = *(VObj**)s;
    o->v13(*(void**)(s + 0xF8));
    o = *(VObj**)s;
    o->v11(*(void**)((char*)o + 0xE4), *(void**)(s + 0xF8));

    o = *(VObj**)s;
    o->v13(*(void**)(*(char**)(s + 0x64) + 0x10));
}
