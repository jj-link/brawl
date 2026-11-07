#pragma force_active on
extern "C" {
void fn_88_4CFC(void* self);
void* memset(void* dst, int c, unsigned int n);
extern char lbl_88_data_1480[];
char* fn_88_5610(char* self);
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
extern "C" char* fn_88_5610(char* self) {
    fn_88_4CFC(self);
    *(unsigned char*)(self + 0x180) = 0;
    *(char**)(self + 0x3c) = lbl_88_data_1480;
    memset(self + 0x184, 0, 0x30);
    SubObj* s = (SubObj*)(self + 0xd0);
    if (s == 0) return self;
    s->f8 = 12;
    s->v4(0, 15);
    { char* p = s->p4; *(unsigned int*)(p + 0x4) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x84) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x104) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x184) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x204) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x284) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x304) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x384) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x404) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x484) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x504) |= 1; }
    { char* p = s->p4; *(unsigned int*)(p + 0x584) |= 1; }
    return self;
}