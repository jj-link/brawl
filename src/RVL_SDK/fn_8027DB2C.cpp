#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(int, int);
    virtual void slot5(void*, int, int);
};
struct HashTable { u64* entries; int count; int mask; };
extern Object_vptr_0* lbl_805A0EB8;
extern "C" void fn_80281D64(void*, int, int);
extern "C" void fn_8027D688(HashTable*, u64, u64);
extern "C" void fn_8027DB2C(HashTable* table, int capacity) {
    u64* keys;
    u64* values;
    int flag;
    int size;
    u64* old;
    old = table->entries;
    flag = table->count & 0x80000000;
    size = table->mask + 1;
    table->entries = (u64*)lbl_805A0EB8->slot4(capacity * 16, 0x15);
    fn_80281D64(table->entries, 0, capacity * 8);
    table->count = 0;
    table->mask = capacity - 1;
    keys = old;
    values = old + size;
    for (int i = 0; i < size; keys++, values++, i++) {
        if (*keys != 0)
            fn_8027D688(table, *keys, *values);
    }
    if (flag == 0)
        lbl_805A0EB8->slot5(old, size * 16, 0x15);
}