#pragma force_active on
extern "C" int OSIsThreadTerminated(void*);
extern "C" void fn_801521A0(void*);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_804619F4[];

extern "C" int fn_80155BD0(void* self) {
    int t = (OSIsThreadTerminated((char*)self + 8) - 1) == 0;
    if (t) {
        return 0;
    }
    if (*(int*)((char*)self + 0x350) == 0x64) {
        return 0;
    }
    fn_801521A0(*(void**)((char*)self + 0x394));
    *(unsigned char*)((char*)self + 0x398) = 1;
    netReport__FPCce(lbl_804619F4);
    return 1;
}
