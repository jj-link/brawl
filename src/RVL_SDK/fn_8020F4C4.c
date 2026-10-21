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
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int fn_8020E98C(void *, Info *);
extern void *memcpy(void *, const void *, unsigned long);

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

int fn_8020F4C4(int *out, u32 id)
{
    Info info;
    u8 value[8];
    int interrupts;
    int success = 0;

    interrupts = OSDisableInterrupts();
    if (find_info(id, &info) && info.type == 0xE0) {
        memcpy(value, info.data, info.size);
        success = 1;
    }
    OSRestoreInterrupts(interrupts);

    if (success) {
        int result;
        switch (value[0]) {
        default:
            result = 1;
            break;
        case 0:
            result = 0;
            break;
        }
        *out = result;
        return 1;
    }
    return 0;
}
