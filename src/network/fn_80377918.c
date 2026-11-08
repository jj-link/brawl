#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef struct Inner { u8 pad[0x40]; s32 state; } Inner;
typedef struct Obj { u8 pad[8]; Inner *inner; u8 pad2[0x5A]; u16 field_66; u8 pad3[0x28]; s32 field_90; } Obj;
extern void *memcpy(void *, const void *, unsigned long);
extern s32 fn_8037442C(void *, void *, s32, s32, u16);
extern s16 lbl_8059F980;
s32 fn_80377918(Obj *arg0) {
    u8 buf[12];
    s16 hdr;
    s32 len = 0;
    s32 temp_r6;
    u16 temp_r7;
    if (arg0->inner->state == 2) {
        hdr = 5;
        memcpy(buf, &hdr, 2);
        len = 2;
    }
    memcpy(buf + len, &lbl_8059F980, 2);
    len += 2;
    buf[len++] = 0x64;
    temp_r6 = len + 1;
    temp_r7 = arg0->field_66;
    buf[len] = (u8)((unsigned int)temp_r7 >> 8);
    buf[temp_r6] = (u8)temp_r7;
    if (fn_8037442C(arg0, buf, len + 2, temp_r6, temp_r7) == 0) return 0;
    arg0->field_90 = 0;
    return 1;
}