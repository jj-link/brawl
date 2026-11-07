#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Entry {
    u32 handle;
    unsigned char pad[0x50];
    u32 size;
    unsigned char pad2[0x8C];
    u32 flags;
    unsigned char tail[8];
} Entry;

typedef struct Info {
    u32 blocks;
    u16 cylinders;
    u8 heads;
    u8 sectors;
    u16 sectorSize;
    u32 unkC;
    u32 unk10;
} Info;

extern Entry lbl_805980D8[];
extern int lbl_805A1280;

extern void fn_803EC3D4(int);
extern void fn_803EC418(int);

int fn_803ED764(u32 handle, Info *info)
{
    Entry *entry = 0;
    u16 i;
    int status;
    Entry *candidate;
    u32 blocks;

    fn_803EC3D4(lbl_805A1280);
    if (handle == 0 || info == 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    for (i = 0; i < 23; ++i) {
        candidate = &lbl_805980D8[i];
        if (candidate->handle == handle) {
            entry = candidate;
            break;
        }
    }

    status = i == 23 ? -22 : 0;
    if (status != 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    blocks = entry->size >> 9;
    info->blocks = blocks;
    info->cylinders = blocks / 255 / 63 / 512;
    info->heads = 0xFF;
    info->sectors = 0x3F;
    info->sectorSize = 0x200;
    info->unkC = 0;
    info->unk10 = 0;
    fn_803EC418(lbl_805A1280);
    return 0;
}
