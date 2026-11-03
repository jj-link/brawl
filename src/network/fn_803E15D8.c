#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 count; u32 other; } Node;
typedef struct { u16 size; u8 pad[4]; u8 factor; } Info;
typedef struct { char pad0[8]; Node *base; int flag; int value; char pad1[0x1c]; Node *node; Info *info; } Object;
extern int fn_803E0F1C(Object *, u32, u32, u32, int *);
int fn_803E15D8(Object *self, u32 arg, int *out) {
    u32 count;
    u32 index;
    u32 amount = arg;
    int result;
    *out = 0;
    count = self->base->count;
    if (count < 2) return 0;
    if (self->flag != 0) {
        *out = self->value + 1;
        return 0;
    }
    if (self->node->other != 0) {
        if (arg <= (self->node->count + 1) * (self->info->size * self->info->factor)) {
            *out = self->node->count + 1;
            return 0;
        }
        *out = self->node->count;
        count = self->node->other;
        index = self->node->count + 1;
        amount = arg - self->node->count * (self->info->size * self->info->factor);
    } else {
        index = 1;
    }
    result = fn_803E0F1C(self, count, index, amount, out);
    if (result != 0) return result;
    return 0;
}