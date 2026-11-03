#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 pad0[8];
    u8 type;
    u8 pad9[7];
    u32 size;
    u32 pad14;
    void *data;
} Info;
extern u32 lbl_805A0BC4;
extern int lbl_805A0BC8;
extern u8 lbl_804ED520[];
extern u8 lbl_805A0BCD;
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int fn_8020E98C(void *, Info *);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_8020EB24(u32);
extern int fn_8020ECB4(u32, u32, void *, int);
static inline int find_info(u32 id, Info *info)
{
    u8 *base = lbl_804ED520;
    u8 *tableOffset;
    u16 offset;
    if (id < lbl_805A0BC4 && (tableOffset = (u8 *)lbl_805A0BC8) != 0) {
        tableOffset = base + (u32)tableOffset;
        offset = ((u16 *)tableOffset)[-id];
        if (offset != 0) {
            return fn_8020E98C(base + *(u16 *)(base + offset), info);
        }
    }
    return 0;
}
int fn_8020F130(void *arg0, u32 arg1, u32 arg2)
{
    Info info;
    int result;
    int interrupts;
    interrupts = OSDisableInterrupts();
    if (find_info(arg1, &info)) {
        if (info.type == arg2) {
            if (fn_803F6150(info.data, arg0, info.size) != 0) {
                memcpy(info.data, arg0, info.size);
                lbl_805A0BCD = 1;
            }
            result = 1;
        } else {
            fn_8020EB24(arg1);
            goto fallback;
        }
    } else {
fallback:
        result = fn_8020ECB4(arg1, arg2, arg0, 0);
    }
    OSRestoreInterrupts(interrupts);
    return result;
}