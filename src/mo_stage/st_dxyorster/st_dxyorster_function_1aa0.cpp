#pragma force_active on
extern "C" {
void fn_76_BE0(char* self, const char* name);
void* memset(void* dst, int c, unsigned int n);
extern char lbl_76_data_11D0[];

char* fn_76_1AA0(char* self, const char* name);
}

class SubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
    void* p4;
    int f8;
};

extern "C" char* fn_76_1AA0(char* self, const char* name) {
    fn_76_BE0(self, name);
    *(unsigned char*)(self + 0x158) = 0;
    *(char**)(self + 0x3c) = lbl_76_data_11D0;
    *(unsigned int*)(self + 0x15c) = 0;
    *(unsigned int*)(self + 0x160) = 0;
    *(unsigned int*)(self + 0x164) = 0;
    *(unsigned int*)(self + 0x168) = 0;
    *(unsigned int*)(self + 0x16c) = 0;
    *(unsigned int*)(self + 0x170) = 0;
    *(unsigned int*)(self + 0x174) = 0;
    memset(self + 0x178, 0, 0x24);
    SubObj* s = (SubObj*)(self + 0xd0);
    if (s == 0) return self;
    s->f8 = 1;
    s->v4(0, 0xf);
    unsigned int* p = (unsigned int*)s->p4;
    p[1] |= 1;
    return self;
}
