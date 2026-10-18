#pragma force_active on
typedef unsigned char u8;

extern const char lbl_41_data_E628[];
extern const float lbl_41_rodata_FA0;

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_HpZero__10wnemSimpleFl(void*, long);
extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);

struct VBase {
    virtual int call0();
    virtual int call1();
    virtual int call2();
    virtual int call3();
};

extern "C" void fn_41_44B80(void* a, void* b) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;

    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_E628);
        setProcFnc_HpZero__10wnemSimpleFl(a, 5);
        setProcFnc_TouchGround__10wnemSimpleFl(a, 6);
    }

    void* c = *(void**)((char*)b + 0xD8);
    VBase* d = (VBase*)*(void**)((char*)c + 0x18);
    int e = d->call2();
    int f = ((VBase*)e)->call2();

    if (f != 10000) {
        void* g = *(void**)((char*)a + 0x2184);
        if (g) {
            *(float*)((char*)a + 0x2200) = lbl_41_rodata_FA0;
            *(float*)((char*)a + 0x2204) = *(float*)((char*)g + 0x5C);
        }
    }
}
