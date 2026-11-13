#pragma force_active on
#include <types.h>
extern "C" int fn_8018D45C(void*, void**, void*);
extern "C" int fn_8018D37C(void*, void**, void*);
struct Object {
    char pad[0x14];
    int table1Offset;
    int table2Offset;
    int entries1Offset;
    int entries2Offset;
    char pad24[0x0C];
    u16 count1;
    u16 count2;
};
extern "C" bool fn_80193764(Object** arg0, void* arg1) {
    Object* obj = *arg0;
    int count1 = obj->count1;
    int count2 = obj->count2;
    char* table1 = obj->table1Offset ? (char*)obj + obj->table1Offset : 0;
    char* table2 = obj->table2Offset ? (char*)obj + obj->table2Offset : 0;
    int* entries2;
    int* entries1;
    int* t1;
    int i;
    int resolved;
    entries1 = obj->entries1Offset ? (int*)((char*)obj + obj->entries1Offset) : 0;
    entries2 = obj->entries2Offset ? (int*)((char*)obj + obj->entries2Offset) : 0;
    t1 = (int*)table1;
    resolved = 0;
    for (i = 0; i < count1; i++) {
        if (*entries1) {
            resolved++;
        } else {
            void* data = table1 + *(int*)t1;
            void* name = (char*)data - 4;
            int result = fn_8018D45C(arg1, &name, data);
            if (result) {
                *entries1 = result;
                resolved++;
            }
        }
        entries1++;
        t1++;
    }
    table1 = table2;
    entries1 = entries2;
    int j;
    for (j = 0; j < count2; j++) {
        if (*entries1) {
            resolved++;
        } else {
            void* data = table2 + *(int*)table1;
            void* name = (char*)data - 4;
            int result = fn_8018D37C(arg1, &name, data);
            if (result) {
                *entries1 = result;
                resolved++;
            }
        }
        entries1++;
        table1 += 4;
    }
    return resolved == (count1 + count2);
}