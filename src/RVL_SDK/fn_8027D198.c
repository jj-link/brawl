#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct HashTable {
    u32* table;
    u32 unk4;
    u32 mask;
};

u32 fn_8027D198(struct HashTable* t, u32 key)
{
    u32 mask = t->mask;
    u32* tab = t->table;
    u32 idx = mask & ((key >> 4) * 0x9E3779B1);

    while (((s32*)tab)[idx] != 0) {
        if (key == tab[idx]) {
            return idx;
        }
        idx = (idx + 1) & ((u32*)t)[2];
    }

    return mask + 1;
}
