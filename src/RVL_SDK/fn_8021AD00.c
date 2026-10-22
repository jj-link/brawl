#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void* memcpy(void*, const void*, u32);
typedef struct { u8 pad[0xa0]; u8 a[2][0x60]; } S;
extern S* lbl_804F6810[];

void fn_8021AD00(int idx) {
    S* s = lbl_804F6810[idx];
    int en = OSDisableInterrupts();
    u8* sb = (u8*)s;
    u8* src = s->a[(u8)(sb[0x8c8] == 0)];
    if (*(u8**)(sb + 0x8ac) != 0) {
        u32 t;
        *(u32*)(sb + 0x8b0) += 1;
        if (*(u32*)(sb + 0x8b0) >= *(u32*)(sb + 0x8b4)) *(u32*)(sb + 0x8b0) = 0;
        t = *(u32*)(sb + 0x8b8);
        if (t <= 2) {
            memcpy(*(u8**)(sb + 0x8ac) + *(u32*)(sb + 0x8b0) * 0x2a, src, 0x2a);
        } else if (t - 3 <= 2) {
            u32 n = 0x2a;
            u8* d = *(u8**)(sb + 0x8ac) + *(u32*)(sb + 0x8b0) * 0x32;
            if (((signed char*)src)[0x29] == 0) n = 0x32;
            memcpy(d, src, n);
        } else if (t - 6 <= 2) {
            u32 n = 0x2a;
            u8* d = *(u8**)(sb + 0x8ac) + *(u32*)(sb + 0x8b0) * 0x36;
            if (((signed char*)src)[0x29] == 0) n = 0x36;
            memcpy(d, src, n);
        } else {
            u32 n = 0x2a;
            u8* d = *(u8**)(sb + 0x8ac) + *(u32*)(sb + 0x8b0) * 0x5a;
            if (((signed char*)src)[0x29] == 0) n = 0x5a;
            memcpy(d, src, n);
        }
    }
    if (*(void (**)(int))(sb + 0x8a8) != 0) (*(void (**)(int))(sb + 0x8a8))(idx);
    *(u16*)(sb + 0x984) += 1;
    OSRestoreInterrupts(en);
}
