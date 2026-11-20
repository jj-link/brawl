#include <types.h>
#include <gm/gm_global.h>

#pragma force_active on

struct Entry {
    u16 a, b;
    u32 c[20];
    u32 d[35];
    u16 e[4], i, j;
    u8 k;
    u16 l;
    u32 m;
    u8 n[45];
};

struct Item {
    u8 a;
    u8 pad;
    s16 index;
};

struct Menu {
    u8 pad[0x1ec];
    u16 selected, first;
    Item items[122];
    u16 count;
};

extern "C" {
void* fn_8004D138(void*, int);
s32 fn_8004D148(void*);
void fn_8004D20C(void*, int);

void fn_16_2C20(void* self, int index)
{
    Menu* arg = (Menu*)self;
    int removed = -1;
    void* global = g_GameGlobal;
    u32 offset = index * 4;
    s16 value = arg->items[index].index;

    if ((u16)(value + 2) > 1)
        removed = value;

    Entry* dst;
    int i;
    s32 count = fn_8004D148(global);

    for (i = removed; i < count - 1; ++i) {
        dst = (Entry*)fn_8004D138(global, i);
        Entry* src = (Entry*)fn_8004D138(global, i + 1);
        *dst = *src;
    }

    fn_8004D20C(global, count - 1);

    Menu* base = (Menu*)((u8*)self + offset);
    for (; index < arg->count - 1; ++index) {
        base->items[0].a = base->items[1].a;
        base->items[0].index = base->items[1].index;
        base = (Menu*)((u8*)base + 4);
    }

    --arg->count;

    s16 v;
    int j = 0;
    Item* p = arg->items;
    for (; j < arg->count; ++j, ++p) {
        v = p->index;
        if (v != -1 && v != -2 && v > removed)
            p->index = v - 1;
    }

    if (arg->count >= 1 && arg->count < 7) {
        if (*(s16*)((u8*)self + (arg->count << 2) + 0x1ee) == -2)
            --arg->count;
    }

    if (arg->first + 5 >= arg->count) {
        if (arg->first != 0)
            --arg->first;

        if (arg->first + arg->selected >= arg->count) {
            int v = arg->count - arg->first - 1;
            if (v >= 0)
                arg->selected = v;
            else
                arg->selected = 0;
        }
    }
}
}