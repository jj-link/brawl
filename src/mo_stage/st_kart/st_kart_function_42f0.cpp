#pragma force_active on
extern "C" {
extern char lbl_49_data_ED8[];
void fn_49_13B0(void* self);
}

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
    char* node;
    int flag;
};

extern "C" char* fn_49_42F0(char* self) {
    fn_49_13B0(self);
    SubObj* s = (SubObj*)(self + 0xd0);
    *(char**)(self + 0x3c) = lbl_49_data_ED8;
    *(int*)(self + 0x158) = 0;
    *(unsigned char*)(self + 0x15c) = 0;
    *(unsigned char*)(self + 0x15d) = 0;
    *(int*)(self + 0x160) = 0;
    *(int*)(self + 0x164) = 0;
    *(int*)(self + 0x168) = 0;
    *(int*)(self + 0x16c) = 0;
    *(int*)(self + 0x170) = 0;
    if (s == 0) {
        return self;
    }
    s->flag = 1;
    s->v4(0, 15);
    {
        char* p = s->node;
        *(unsigned int*)(p + 0x4) |= 1;
    }
    {
        char* p = s->node;
        *(unsigned int*)(p + 0x4) |= 2;
    }
    return self;
}
