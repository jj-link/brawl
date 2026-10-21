#pragma force_active on
extern "C" {
int fn_14_3424(void* self, int v);
void fn_14_39BC(void* self, int mode);
int fn_800B5854(void* p, int a, int b, int c, int d);
void fn_14_3C50(void* self);
void fn_14_1C80(void* self, int v);
void fn_14_3A7C(void* self, int v);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
void printf__5MuMsgFUlPCce(void* msg, unsigned long idx, const char* fmt, ...);
}

extern char lbl_14_data_568[];

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
    virtual void target(void* a, void* b);
};

extern "C" void fn_14_74F4(void* self) {
    char* s = (char*)self;
    fn_14_3424(self, 5);
    fn_14_39BC(self, 0);
    fn_800B5854(*(void**)(s + 0xb0), 0, 1, 1, 0);
    {
        VObj* o = *(VObj**)(s + 0x204);
        o->target(*(void**)((char*)o + 0xe4), *(void**)(s + 0x1e4));
    }
    printIndex__5MuMsgFUlUlPv(*(void**)(s + 0x24cc), 0x17, 0x13, 0);
    *(unsigned char*)(s + 0x2500) = 0;
    fn_14_3C50(self);
    fn_14_1C80(self, 1);
    printf__5MuMsgFUlPCce(*(void**)(s + 0x24cc), 0x1b, lbl_14_data_568);
    fn_14_3A7C(self, 0);
}
