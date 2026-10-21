#pragma force_active on

typedef unsigned int u32;

struct Entry {
    u32 threshold;
    int id;
};

struct Table {
    Entry entries[14];
};

extern "C" {
extern void* g_GameGlobal;
u32* fn_8004E580(void*);
u32 fn_80050994();
extern const Table lbl_80406E28;

int fn_800568C8() {
    u32* bits = fn_8004E580(g_GameGlobal);
    u32 value = fn_80050994();
    Table table = lbl_80406E28;

    for (int i = 13; i >= 0; --i) {
        Entry* entry = &table.entries[i];
        if (value >= entry->threshold) {
            int bit;
            int id = entry->id;
            bit = id * 3;
            int check = bit + 1;
            if (!(bits[check / 32] & (1 << (check % 32)))) {
                bits[bit / 32] |= 1 << (bit % 32);
                return id;
            }
        }
    }
    return -1;
}
}
