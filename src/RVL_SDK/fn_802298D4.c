#pragma force_active on
typedef unsigned int u32;

extern void DCFlushRange(void* buf, u32 len);
extern int fn_80229330(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);

void fn_802298D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                 u32 a7, u32 a8) {
    DCFlushRange((void*)a6, a5);
    fn_80229330(a0, a1, a2, a3, a4, a5, a6, a7, a8, 1);
}
