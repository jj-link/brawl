#pragma force_active on
typedef unsigned char u8;

extern const char lbl_41_data_E6B3[];
extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_HpZero__10wnemSimpleFl(void*, long);

class Mod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void exec(int, int);
};

extern "C" void fn_41_44E90(void* a, void* b) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;
    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_E6B3);
        void* mod = *(void**)((char*)b + 0xD8);
        Mod* obj = (Mod*)*(void**)((char*)mod + 0x14);
        obj->exec(2, 1);
        setProcFnc_HpZero__10wnemSimpleFl(a, 8);
    }
}
