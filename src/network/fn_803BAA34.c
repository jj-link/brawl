#include <types.h>

#pragma force_active on

typedef struct Sector {
    u16 size;
    char pad02[0x1e];
    u8 shift;
} Sector;

typedef struct Node {
    char pad00[0x264];
    u32 length;
    Sector *sector;
} Node;

typedef struct File {
    char pad00[8];
    Node *node;
    char pad0c[0x10];
    u32 pos;
    s32 block;
    u32 index;
    u16 offset;
} File;

extern s32 fn_803B722C(u8 *, u32, u32, s32 *, s32 *);
extern s32 fn_803C0440(Sector *, u8 *, s32, u16, u32, u32 *, int);
extern void fn_803B0468(File *, int);

static inline u32 BlockCount(Sector *volume, u32 position)
{
    return (position >> volume->shift) + ((position & (volume->size - 1)) ? 1 : 0);
}

static inline s32 Write(Sector *ctx, File *file, u8 *buffer, u32 length, u32 *done)
{
    u32 count, nextpos, updatedblock, newblock, currentpos, finalpos;
    Sector *midsector, *endsector;
    s32 result;
    *done = 0;
    result = fn_803C0440(ctx, buffer, file->block, file->offset, length, &count, 1);
    if (result != 0 && count == 0)
        return result;
    *done = count;
    newblock = file->block;
    if (file == 0)
        midsector = 0;
    else
        midsector = file->node->sector;
    nextpos = file->offset + *done;
    updatedblock = (nextpos >> midsector->shift) + newblock;
    if ((midsector->size - 1) & nextpos)
        file->block = updatedblock;
    else
        file->block = -1;
    currentpos = file->pos + *done;
    file->pos = currentpos;
    if (currentpos > file->node->length)
        file->node->length = currentpos;
    if (file == 0)
        endsector = 0;
    else
        endsector = file->node->sector;
    finalpos = file->pos;
    file->index = finalpos >> endsector->shift;
    file->offset = finalpos & (endsector->size - 1);
    fn_803B0468(file, updatedblock);
    return 0;
}

s32 fn_803BAA34(Sector *ctx, File *file, u8 *buffer, u32 length, u32 *written)
{
    s32 blocks;
    u32 count;
    s32 result;
    u32 done;
    u32 end;
    u32 pos;
    u32 posBlocks;
    u32 endBlocks;
    u32 newblock;
    u32 updatedblock;
    u32 nextpos;
    u32 currentpos;
    u32 finalpos;
    Sector *sector;
    Sector *midsector;
    Sector *endsector;

    *written = 0;
    result = fn_803B722C((u8 *)file->node + 4, file->index, length,
                          &file->block, &blocks);
    if (result != 0)
        return result;

    if (blocks == 0 || (u32)(file->block + 0x10000) == 0xffff) {
        end = file->node->length;
        if (file == 0)
            sector = 0;
        else
            sector = file->node->sector;

        posBlocks = BlockCount(sector, file->pos);
        endBlocks = BlockCount(sector, end);
        if (posBlocks != endBlocks)
            file->block = -1;

        file->pos = end;
        if (file == 0)
            sector = 0;
        else
            sector = file->node->sector;

        pos = file->pos;
        file->index = pos >> sector->shift;
        file->offset = pos & (sector->size - 1);
        return 0x1c;
    }

    if (length > (u32)(blocks << ctx->shift))
        length = blocks << ctx->shift;

    result = Write(ctx, file, buffer + *written, length, &done);

    *written = done;
    if (result != 0)
        return result;
    return 0;
}
