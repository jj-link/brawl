#pragma force_active on
typedef unsigned char u8;

extern "C" void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
extern "C" void setProcFnc_HitShell__10wnemSimpleFl(void*, long);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
extern "C" void changeProcFnc__10wnemSimpleFll(void*, long, long);

extern "C" void fn_41_6427C(void* a) {
    u8 x = *((u8*)a + 0x2214);
    *((u8*)a + 0x2214) = 0;
    if (x) {
        setProcFnc_TouchGround__10wnemSimpleFl(a, 0x43);
        setProcFnc_HitShell__10wnemSimpleFl(a, 0x25);
        executeAnimCmd__10wnemSimpleFUl(a, 4);
        executeAnimCmd__10wnemSimpleFUl(a, 5);
    }
    if (*((u8*)a + 0x2218)) {
        changeProcFnc__10wnemSimpleFll(a, 0x25, 1);
    }
}
