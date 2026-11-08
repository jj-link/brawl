#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u16 sectorSize;
    u8 pad02[4];
    u8 count;
    u8 pad07[0x1a];
    u8 shift;
    u8 pad22[0xe];
    s32 cursor;
} Self;

typedef struct {
    u8 pad[8];
    void *data;
} Node;

extern s32 fn_803DA454(void *, s32, void **, s32 *);
extern void fn_803DA55C(void *, void *);
extern void fn_803D634C(void *, s32, u32);
extern s32 PFSEC_ReadData(void *, void *, s32, s32, s32, u32 *, s32);
extern s32 PFSEC_WriteData(void *, void *, s32, s32, s32, u32 *, s32);

s32 fn_803DFAFC(void *arg0, s32 arg1) {
    s32 sector;
    s32 base;
    s32 i;
    Self *self;
    void *sp10;
    s32 spC;
    u32 sp8;
    s32 r;

    self = (Self *)arg0;
    r = fn_803DA454(self, -1, &sp10, &spC);
    if (r != 0) {
        return r;
    }

    i = 0;
    base = self->cursor + ((arg1 - 2) << self->shift);

    while ((u32)i < (u32)self->count) {
        sector = base + i;

        r = PFSEC_ReadData(self, ((Node *)sp10)->data, sector, 0, self->sectorSize, &sp8, 1);
        if (r != 0 || sp8 != self->sectorSize) {
            break;
        }
        fn_803D634C(((Node *)sp10)->data, 0, self->sectorSize);
        r = PFSEC_WriteData(self, ((Node *)sp10)->data, sector, 0, self->sectorSize, &sp8, 1);
        if (r != 0 || sp8 != self->sectorSize) {
            break;
        }
        i++;
    }

    fn_803DA55C(self, sp10);
    return 0;
}