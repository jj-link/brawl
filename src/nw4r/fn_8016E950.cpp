#pragma force_active on
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {
extern void fn_8015BFB4(void *, void *);
extern void fn_8016E4F4(void *, s32, void *);
extern void *memset(void *, int, unsigned long);

void *fn_8016E950(void *arg0, void *arg1) {
    u32 base = (u32)arg1 + *(u16 *)((char *)arg1 + 0xc);
    char *r31 = (char *)(base + 8);
    memset((void *)((u32)r31 + 4), 0, 8);
    fn_8015BFB4(arg0, r31);
    s32 r4 = *(s32 *)((char *)arg0 + 0xc);
    char *r5 = r31 + *(s32 *)r31;
    *(s32 *)((char *)arg0 + 0xc) = r4 + *(u16 *)(r5 + 4);
    fn_8016E4F4(r31, r4, r5);
    return r31;
}
}
