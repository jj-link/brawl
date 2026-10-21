#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Entry {
    u32 a;
    int b;
};

struct Obj {
    u8 pad[0xfc];
    Entry* table;
    u8 count;
};

extern "C" {
int fn_80187CB4(Obj* obj, u32 index) {
    if (index >= obj->count) {
        return 0;
    }
    return obj->table[index].b;
}
}
