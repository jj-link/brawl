#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 pad[0xC];
    u8 *cur;
    u32 end;
} Reader;

s32 fn_80260FC0(u8 *dst, Reader *r) {
    u8 *p = r->cur;
    if ((u32) p >= r->end) {
        return -0x90;
    }
    *dst = *p;
    p++;
    r->cur = p;
    return ((u32) p >= r->end) ? -0x90 : 0;
}
