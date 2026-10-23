#pragma force_active on

typedef int s32;
typedef unsigned int u32;

struct Entry {
    s32 value;
    s32 unknown;
};

struct Table {
    Entry* entries;
    u32 count;
};

struct Holder {
    char pad[0x70];
    Table* table;
};

struct Object {
    char pad[0x2184];
    Holder* holder;
};

extern "C" char lbl_41_data_4018[];
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" void executeAnimCmd__10wnemSimpleFlll(Object*, s32, s32, s32);

extern "C" int executeAnimCmd__10wnemSimpleFUl(Object* self, u32 index) {
    char* base = lbl_41_data_4018;
    Table* t = self->holder->table;

    if (!t) {
        wnemReport__FPCce(base + 0x457);
        return 0;
    }

    if (index >= t->count) {
        wnemReport__FPCce(base + 0x49d, index, t->count);
        return 0;
    }

    s32 val = t->entries[index].value;
    if (!val) {
        wnemReport__FPCce(base + 0x4f4, index);
        return 0;
    }

    s32 extra = t->entries[index].unknown;
    int flag = 0;
    if (extra == 4) {
        flag = 1;
    }

    executeAnimCmd__10wnemSimpleFlll(self, val, extra, flag);
    return 1;
}
