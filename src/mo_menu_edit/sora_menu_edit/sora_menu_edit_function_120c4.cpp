#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Entry {
    u8 data[0x30];
};

struct Global {
    u8 pad0[0x194];
    Entry* entries;
    u32 count;
    u8 pad1[0x1fc - 0x19c];
    u32 table[4][50];
};

struct Req {
    u8 pad0[0x8];
    u32 a;
    u32 b;
};

extern "C" {
extern Global* lbl_805A01D8;
}

extern "C" Entry* fn_5_120C4(Req* req) {
    Global* g = lbl_805A01D8;
    u32 v = g->table[req->a][req->b];
    if (v >= g->count) {
        return 0;
    }
    return &g->entries[v];
}
