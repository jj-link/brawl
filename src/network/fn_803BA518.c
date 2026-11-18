#include <types.h>
#pragma force_active on

typedef struct {
    u16 blockSize;
    u8 pad02[0x1E];
    u8 blockShift;
} Volume;

typedef struct {
    u8 pad00[0x264];
    u32 size;
    Volume *volume;
} Node;

typedef struct {
    u32 unk00;
    u32 unk04;
    Node *node;
    u8 pad0C[0x10];
    u32 position;
    u32 sector;
    u32 block;
    u16 offset;
} File;

extern int fn_803B7080(void *, u32, int, void *);
extern int fn_803C0440(void *, void *, u32, u16, u32, int *, int);
extern void fn_803B0468(File *, int);

static inline u32 BlockCount(Volume *volume, u32 position)
{
    return (position >> volume->blockShift) +
           ((position & (volume->blockSize - 1)) ? 1 : 0);
}

static inline void SetSector(File *self, u32 sector)
{
    self->sector = sector;
}

static inline void Advance(File *self, u32 amount, u32 sector)
{
    Volume *volume;
    u32 next;
    u32 position;
    u32 cand;

    if (self == 0) {
        volume = 0;
    } else {
        volume = self->node->volume;
    }

    next = self->offset + amount;
    cand = sector + (next >> volume->blockShift);
    if ((volume->blockSize - 1) & next) {
        SetSector(self, cand);
    } else {
        SetSector(self, -1);
    }

    position = self->position + amount;
    self->position = position;
    if (position > self->node->size) {
        self->node->size = position;
    }

    if (self == 0) {
        volume = 0;
    } else {
        volume = self->node->volume;
    }

    self->block = self->position >> volume->blockShift;
    self->offset = self->position & (volume->blockSize - 1);
    fn_803B0468(self, (int)cand);
}

int fn_803BA518(u16 *arg0, File *self, void *buffer, u32 length,
                int *written)
{
    int count;
    int result;
    u32 size;
    Volume *volume;
    u32 position;
    u32 sector;

    *written = 0;

    if (self->offset == 0) {
        return 0;
    }

    if (length > (u32)(*arg0 - self->offset)) {
        length = *arg0 - self->offset;
    }

    if ((u32)(self->sector + 0x10000) == 0xFFFF) {
        result = fn_803B7080((u8 *)self->node + 4, self->block,
                             0, &self->sector);
        if (result != 0) {
            return result;
        }

        if ((u32)(self->sector + 0x10000) == 0xFFFF) {
            size = self->node->size;

            if (self == 0) {
                volume = 0;
            } else {
                volume = self->node->volume;
            }

            position = BlockCount(volume, self->position);
            sector = BlockCount(volume, size);
            if (position != sector) {
                self->sector = -1;
            }

            self->position = size;

            if (self == 0) {
                volume = 0;
            } else {
                volume = self->node->volume;
            }

            self->block = self->position >> volume->blockShift;
            self->offset = self->position & (volume->blockSize - 1);
            return 0x1C;
        }
    }

    result = fn_803C0440(arg0, buffer, self->sector, self->offset,
                         length, &count, 1);
    if (result != 0 && count == 0) {
        return result;
    }

    *written = count;
    Advance(self, count, self->sector);
    return 0;
}
