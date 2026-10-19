#pragma force_active on
typedef unsigned char u8;

extern const char lbl_41_data_1C7BE[];

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
extern "C" void setProcFnc_HitShell__10wnemSimpleFl(void*, long);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);

extern "C" void fn_41_64560(void* a) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;

    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_1C7BE);
        setProcFnc_TouchGround__10wnemSimpleFl(a, 0x27);
        setProcFnc_HitShell__10wnemSimpleFl(a, 0x27);
        executeAnimCmd__10wnemSimpleFUl(a, 6);
    }
}
