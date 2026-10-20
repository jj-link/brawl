#pragma force_active on
extern const char lbl_41_data_ECC8[];

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);

typedef unsigned char u8;

struct VBase7 {
    virtual int c0();
    virtual int c1();
    virtual int c2();
    virtual int c3();
    virtual int c4();
    virtual int c5();
    virtual int c6(int, int);
};

extern "C" void fn_41_47FB4(void* a, void* b) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;
    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_ECC8);
        void* c = *(void**)((char*)b + 0xD8);
        void* d = *(void**)((char*)c + 0x14);
        ((VBase7*)d)->c6(2, 1);
        setProcFnc_TouchGround__10wnemSimpleFl(a, -1);
    }
}
