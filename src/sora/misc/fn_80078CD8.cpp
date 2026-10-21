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

extern "C" void fn_80078CD8(Obj* self, int type, u32 key, u8 val) {
    u32* p;
    Entry* e;
    Entry* base = self->base;
    u32 i = self->idx[type];
    e = &base[i];
    p = &base[i].key;

    while (type == e->type) {
        if (key == *p) {
            base[i].flag = val;
            return;
        }
        p += 2;
        ++e;
        ++i;
    }
}
