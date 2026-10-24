#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u32 key;
    u8 pad[2];
    u8 type;
    u8 flag;
};

struct Obj {
    Entry* base;
    u8 pad[0xB8 - 4];
    u32 idx[16];
};

extern "C" u8 fn_80078D30(Obj* self, int type, u32 key) {
    u32* p;
    Entry* e;
    Entry* base = self->base;
    u32 i = self->idx[type];
    e = &base[i];
    p = &base[i].key;

    while (type == e->type) {
        if (key == *p) {
            return base[i].flag;
        }
        p += 2;
        ++e;
        ++i;
    }
    return 0;
}
