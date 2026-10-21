#pragma force_active on
typedef unsigned char u8;

extern const char lbl_41_data_189C0[];
extern const char lbl_41_data_189E4[];

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
extern "C" void fn_41_31708(void*);
extern "C" long getFrameCounter__10wnemSimpleFl(void*, int);
extern "C" void* fn_41_5E20();
extern "C" void changeProcFnc__10wnemSimpleFll(void*, long, long);

extern "C" void fn_41_5C4C8(void* a) {
    u8* base = (u8*)a;
    u8 r4 = base[0x2214];
    base[0x2214] = 0;
    if (r4) {
        Report__14wnemCommonProcFPCce(lbl_41_data_189C0);
        setProcFnc_TouchGround__10wnemSimpleFl(a, 0x3A);
        fn_41_31708(a);
        executeAnimCmd__10wnemSimpleFUl(a, 1);
        executeAnimCmd__10wnemSimpleFUl(a, 2);
    }
    int fc = getFrameCounter__10wnemSimpleFl(a, 1);
    Report__14wnemCommonProcFPCce(lbl_41_data_189E4, fc);
    if (((u8*)fn_41_5E20())[0x48] == 1) {
        changeProcFnc__10wnemSimpleFll(a, 0x3A, 1);
    }
}
