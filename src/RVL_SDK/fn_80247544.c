#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SdpUuidDesc {
    u32 w[5];
} SdpUuidDesc;

extern unsigned char lbl_8052C9B8[0x408];
extern void fn_802568BC(void *, unsigned int, unsigned short, void *, unsigned short, unsigned short *);
extern u32 fn_80256C34(void *, void *, void *);
extern void fn_8024760C(void);

int fn_80247544(void *arg0, void *arg1, unsigned int arg2, unsigned int arg3) {
    SdpUuidDesc uuid;

    if (lbl_8052C9B8[0x380] != 0) {
        return 0x10;
    }
    *(void **)&lbl_8052C9B8[0x388] = arg1;
    *(u16 *)&uuid = 2;
    *(u16 *)((char *)&uuid + 4) = 0x1124;
    fn_802568BC(arg1, arg2, 1, &uuid, 0, 0);
    if ((u8)fn_80256C34(arg0, arg1, fn_8024760C) != 0) {
        *(unsigned int *)&lbl_8052C9B8[0x384] = arg3;
        lbl_8052C9B8[0x380] = 1;
        return 0;
    }
    return 3;
}
