#pragma force_active on
extern "C" {
void fn_79_1A64(char* self);
void* memset(void* dst, int c, unsigned int n);
extern char lbl_79_data_1090[];

char* fn_79_1C40(char* self);
}

class SubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
    char* p4;
    int f8;
};

extern "C" char* fn_79_1C40(char* self) {
    fn_79_1A64(self);
    *(int*)(self + 0x150) = 0;
    *(char**)(self + 0x3c) = lbl_79_data_1090;
    *(int*)(self + 0x154) = 0;
    *(unsigned char*)(self + 0x158) = 0;
    memset(self + 0x159, 0, 0x1E);
    memset(self + 0x178, 0, 0x78);
    *(unsigned char*)(self + 0x1F0) = 0;
    *(int*)(self + 0x1F4) = 0;
    *(int*)(self + 0x1F8) = 0;
    *(int*)(self + 0x1FC) = 0;
    *(int*)(self + 0x200) = 0;
    *(int*)(self + 0x204) = 0;
    *(int*)(self + 0x208) = 0;
    *(int*)(self + 0x20C) = 0;
    memset(self + 0x210, 0, 0x78);
    SubObj* s = (SubObj*)(self + 0xD0);
    if (s == 0) return self;
    s->f8 = 1;
    s->v4(0, 15);
    {
        char* p = s->p4;
        *(unsigned int*)(p + 0x4) |= 1;
    }
    return self;
}
