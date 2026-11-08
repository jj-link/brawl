#pragma force_active on

extern "C" void* fn_61_2320(void*, const char*);
extern "C" void* memset(void*, int, unsigned long);
extern char lbl_61_data_2370[];
extern const float lbl_61_rodata_118;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void method(int, int);

    unsigned int* flags;
    unsigned int x;
};

extern "C" void* fn_61_8410(void* self, const char* name) {
    char* p = (char*)self;
    fn_61_2320(self, name);
    *(void**)(p + 0x3c) = lbl_61_data_2370;
    *(int*)(p + 0x158) = 0;
    *(int*)(p + 0x15c) = 0;
    *(float*)(p + 0x160) = lbl_61_rodata_118;
    *(int*)(p + 0x164) = 0;
    *(int*)(p + 0x168) = 0;
    *(unsigned char*)(p + 0x16c) = 5;
    *(int*)(p + 0x170) = 0;
    *(int*)(p + 0x174) = 0;
    memset(p + 0x178, 0, 0x3c);
    *(unsigned char*)(p + 0x1b4) = 5;
    *(float*)(p + 0x1b8) = lbl_61_rodata_118;
    memset(p + 0x1bc, 0, 5);

    Sub* sub = (Sub*)(p + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->x = 1;
    sub->method(0, 15);
    sub->flags[1] |= 8;
    return self;
}
