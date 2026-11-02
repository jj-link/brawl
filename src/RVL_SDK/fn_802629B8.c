#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef s32 (*FnGetter)(void *, s32, s32, void *);
typedef void (*FnEmit)(void *, s32, u16, s32);
typedef void (*FnFinal)(void *, s32, s32);

extern s32 fn_80263180(void *, s32, s32);
extern void fn_80263FDC(void *, s32, s32);

s32 fn_802629B8(s32 arg0, s32 arg1, void *arg2) {
    u8 sp10[0x100];
    FnFinal sp110;
    u8 *base;
    u8 *r14;
    u8 *r31;
    s32 r30;
    s32 *r29;
    s32 *r28;
    u8 *r27;
    s32 r26;
    s32 r25;
    s32 k;
    s32 r23;
    u16 r22;
    u8 *r21;
    u8 *r20;
    s32 *r19;
    FnEmit emit18;
    FnEmit emit17;
    FnGetter getter;
    u8 *hdr;
    u8 *r5;
    s32 r3;

    base = (u8 *)arg2;
    r21 = base + 0x17DC;
    r14 = base + 0x18;
    r20 = base + 0x44;
    r19 = (s32 *)(base + 0x1828);
    hdr = *(u8 **)(base + 0x19D0);
    getter = *(FnGetter *)(base + 0x1814);
    emit18 = *(FnEmit *)(base + 0x180C);
    emit17 = *(FnEmit *)(base + 0x1810);

    if ((u32)arg0 != *(u32 *)(hdr + 0x24) && (u32)arg1 != *(u32 *)(hdr + 0x28)) {
        sp110 = *(FnFinal *)(base + 0x1818);
    } else {
        sp110 = *(FnFinal *)(base + 0x181C);
    }
    r22 = *(u16 *)(base + 0x19CA);
    r31 = r14;
    r30 = (s32)(r14 + 4);
    r25 = 0;
    while (r25 < r21[0x1B]) {
        k = *r31;
        r5 = r14 + k;
        r26 = (s32)r20 + (r5[0x18] << 8);
        fn_80263FDC(r20, r5[0x1C], r5[0x20]);
        r28 = r19 + k;
        r27 = r21 + r25;
        r29 = r19;
        r23 = 0;
        while (r23 < r27[0x1C]) {
            r3 = getter(sp10, r26, r30, arg2);
            if (r3 < 0) {
                return r3;
            }
            if (k == 0) {
                emit18(sp10, *r29, r22, r3);
            } else {
                emit17(sp10, r28[4], r22, r3);
            }
            r29++;
            r23++;
        }
        r30 += 4;
        r25++;
        r31++;
    }
    sp110(arg2, arg0, arg1);
    if (*(u16 *)(r21 + 0x2A) != 0) {
        r3 = fn_80263180(arg2, arg0, arg1);
        if (r3 < 0) {
            return r3;
        }
    }
    return 0;
}
