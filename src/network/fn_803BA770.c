#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Volume {
    u16 size;
    u8 pad02[0x1E];
    u8 shift;
} Volume;

typedef struct Node {
    u8 pad00[0x264];
    u32 length;
    Volume *volume;
} Node;

typedef struct Obj {
    u8 pad00[8];
    Node *node;
    u8 pad0C[0x10];
    u32 position;
    u32 sector;
    u32 index;
    u16 offset;
} Obj;

extern s32 fn_803B053C(Obj *, s32, s32 *, u32 *);
extern s32 fn_803B7080(void *, u32, s32, u32 *);
extern s32 fn_803C0440(Volume *, void *, u32, u16, s32, s32 *, s32);
extern void fn_803B0468(Obj *, u32);

static inline Volume *GetVolume(Obj *obj)
{
    return obj == 0 ? 0 : obj->node->volume;
}

static inline u32 BlockCount(Volume *volume, u32 position)
{
    return (position >> volume->shift) +
           ((position & (volume->size - 1)) ? 1 : 0);
}

static inline void SetPosition(Obj *obj, u32 position)
{
    Volume *volume;

    obj->position = position;
    volume = GetVolume(obj);
    obj->index = obj->position >> volume->shift;
    obj->offset = obj->position & (volume->size - 1);
}

static inline u32 Advance(Obj *self, u32 amount, u32 sector)
{
    Volume *volume;
    u32 next;
    u32 cand;
    u32 position;

    volume = GetVolume(self);
    next = self->offset + amount;
    cand = sector + (next >> volume->shift);
    if ((volume->size - 1) & next) {
        self->sector = cand;
    } else {
        self->sector = -1;
    }

    position = self->position + amount;
    self->position = position;
    if (position > self->node->length) {
        self->node->length = position;
    }

    volume = GetVolume(self);
    self->index = self->position >> volume->shift;
    self->offset = self->position & (volume->size - 1);
    return cand;
}

s32 fn_803BA770(Volume *arg0, Obj *arg1, void *arg2, s32 arg3,
               s32 arg4, s32 *arg5)
{
    u32 sp10;
    s32 spC;
    s32 result;
    u32 length;
    Volume *volume;
    u32 position;
    u32 sectorCount;
    u32 newSector;

    *arg5 = 0;
    if (arg3 == 0) {
        return 0;
    }

    if ((u32)arg3 > (u32)(arg0->size - arg1->offset) ||
        (u32)arg3 > arg0->size) {
        return 0x1A;
    }

    if (arg4 != 0) {
        result = fn_803B053C(arg1, arg4, &arg3, &sp10);
        if (result != 0) {
            return result;
        }
        if (arg3 == 0) {
            return 0;
        }
        arg1->sector = sp10;
    } else if ((u32)(arg1->sector + 0x10000) == 0xFFFF) {
        result = fn_803B7080((char *)arg1->node + 4, arg1->index,
                             0, &arg1->sector);
        if (result != 0) {
            return result;
        }

        if ((u32)(arg1->sector + 0x10000) == 0xFFFF) {
            length = arg1->node->length;
            volume = GetVolume(arg1);
            position = BlockCount(volume, arg1->position);
            sectorCount = BlockCount(volume, length);
            if (position != sectorCount) {
                arg1->sector = -1;
            }
            SetPosition(arg1, length);
            return 0x1C;
        }
    }

    result = fn_803C0440(arg0, arg2, arg1->sector, arg1->offset,
                         arg3, &spC, 1);
    if (result != 0 && spC == 0) {
        return result;
    }

    *arg5 = spC;
    newSector = Advance(arg1, spC, arg1->sector);
    fn_803B0468(arg1, newSector);
    return 0;
}
