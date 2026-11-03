#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned long long u64;
typedef long long s64;
typedef unsigned int u32;
typedef int s32;

typedef struct HashTable {
    u64 *entries;
    s32 count;
    s32 mask;
} HashTable;

void fn_8027DB2C(HashTable *table, s32 newCapacity);

void fn_8027D688(HashTable *table, u64 key, u64 value) {
    u64 idx;

    if (table->count * 2 > table->mask) {
        fn_8027DB2C(table, table->mask * 2 + 2);
    }
    idx = ((key >> 4) * 0x9E3779B1ULL) & (s64)table->mask;
    while (table->entries[idx] != 0 && table->entries[idx] != key) {
        idx = (idx + 1) & (s64)table->mask;
    }
    table->count += (table->entries[idx] != key);
    table->entries[idx] = key;
    table->entries[idx + table->mask + 1] = value;
}
