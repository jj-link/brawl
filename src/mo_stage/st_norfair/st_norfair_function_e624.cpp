#pragma force_active on

extern "C" void fn_54_2C48(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" char lbl_54_data_315C[];
extern "C" char lbl_54_data_3380[];
extern "C" const float lbl_54_rodata_180;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void method(int, int);

    unsigned int* flags;
    unsigned int x;
};

extern "C" void* fn_54_E624(void* self) {
    char* p = (char*)self;
    fn_54_2C48(self);
    char* seq = p + 0x168;
    *(void**)(p + 0x3c) = lbl_54_data_315C;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 2);
    *(void**)seq = lbl_54_data_3380;
    *(int*)(p + 0x15c) = 0;
    *(unsigned char*)(p + 0x160) = 1;
    *(float*)(p + 0x164) = lbl_54_rodata_180;
    *(int*)(p + 0xc0) = -1;
    *(int*)(p + 0xc4) = -1;
    *(unsigned char*)(p + 0xc8) = 0;
    *(unsigned char*)(p + 0x1dc) = 0;
    *(int*)(p + 0x1e0) = -1;

    Sub* sub = (Sub*)(p + 0xd0);
    if (sub == 0) {
        return self;
    }
    sub->x = 1;
    sub->method(0, 15);
    sub->flags[1] |= 1;
    return self;
}
