#pragma force_active on
typedef unsigned char u8;

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
extern "C" void setProcFnc_HitShell__10wnemSimpleFl(void*, long);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
extern "C" void changeProcFnc__10wnemSimpleFll(void*, long, long);
extern "C" void* fn_41_5E20();
extern char lbl_41_data_18A1C[];

extern "C" void fn_41_5C658(void* a) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;
    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_18A1C);
        setProcFnc_TouchGround__10wnemSimpleFl(a, 0x3C);
        setProcFnc_HitShell__10wnemSimpleFl(a, 0x3C);
        executeAnimCmd__10wnemSimpleFUl(a, 3);
        executeAnimCmd__10wnemSimpleFUl(a, 4);
    }
    if (*((u8*)a + 0x2218)) {
        changeProcFnc__10wnemSimpleFll(a, 0x3C, 1);
        return;
    }
    if (((u8*)fn_41_5E20())[0x48] == 1) {
        changeProcFnc__10wnemSimpleFll(a, 0x3C, 1);
    }
}
