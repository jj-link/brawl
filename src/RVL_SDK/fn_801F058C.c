#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void PPCMtwpar(u32 value);
extern s32 fn_801D5144(void);

void fn_801F058C(void) {
    do {
    } while (fn_801D5144() & 1);
    PPCMtwpar(0x0C008000);
}
