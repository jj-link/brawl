#pragma force_active on
extern "C" void getPrintIndexData__7MessageFPvUlPPcPUl(void* p, unsigned long idx, char** a, unsigned long* b);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" int sprintf(char* s, const char* fmt, ...);
extern "C" void fn_800BF928(void* self, const char* str);
extern char lbl_8059E1F0[5];

extern "C" void fn_800DCC30(char* self, int arg1) {
    char buf[0x80];
    char* spC;
    unsigned long sp8;

    getPrintIndexData__7MessageFPvUlPPcPUl(*(void**)(self + 0x90), 0x13, (char**)&sp8, (unsigned long*)&spC);
    memcpy(buf, (void*)sp8, (unsigned long)spC);
    spC = (char*)((unsigned long)spC + sprintf(buf + (unsigned long)spC, lbl_8059E1F0, arg1));
    fn_800BF928(*(void**)(self + 0xB0), buf);
}
