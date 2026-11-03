#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct SdpUuidDesc {
    u32 w[5];
} SdpUuidDesc;

typedef struct SdpDiscDb {
    u32 mem_size;
    u32 mem_free;
    void *p_first_rec;
    u16 num_uuid;
    u8 pad_e[2];
    SdpUuidDesc uuid[3];
    u16 num_attr;
    u16 attr[12];
    u8 *p_free_mem;
} SdpDiscDb;

extern void *memset(void *, int, unsigned long);
extern void fn_80231A44(u32, const char *, void *, u32, u16, u16);
extern void fn_8025BED4(unsigned long, u8 *);
extern char lbl_80484B98[];
extern u8 lbl_8052D9C0[];

s32 fn_802568BC(SdpDiscDb *arg0, u32 arg1, u16 arg2, SdpUuidDesc *arg3, u16 arg4, u16 *arg5)
{
    u16 i;
    SdpUuidDesc *src;
    u16 *attr_src;

    if (arg0 == 0 || arg1 < 0x6CU || arg4 > 0xCU || arg2 > 3U) {
        if (lbl_8052D9C0[0x4630] >= 1U) {
            fn_80231A44(0xA0000, lbl_80484B98, arg0, arg1, arg2, arg4);
        }
        return 0;
    }

    memset(arg0, 0, arg1);
    arg0->mem_size = arg1 - 0x6C;
    arg0->mem_free = arg1 - 0x6C;
    arg0->p_first_rec = 0;
    arg0->p_free_mem = (u8 *)arg0 + 0x6C;

    src = arg3;
    for (i = 0; i < arg2; i++) {
        arg0->uuid[i] = *src++;
    }
    arg0->num_uuid = arg2;

    attr_src = arg5;
    for (i = 0; i < arg4; i++) {
        arg0->attr[i] = *attr_src++;
    }
    fn_8025BED4(arg4, (u8 *)arg0);
    arg0->num_attr = arg4;
    return 1;
}
