#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

struct Value {
    u32 a, b, c, d;
};

struct Entry {
    char pad0[0x72];
    signed char kind;
    char pad1[0x15];
    Value value;
    char pad2[0x2E];
    u8 other : 7;
    u8 flag : 1;
    char pad3[0x151];
};

extern "C" {
    u8 fn_800C851C();
    void netReport__FPCce(const char*, ...);
    void fn_800D0AE0(void*);
    void fn_80145B98(void*, int);
}

extern char lbl_80459830[];
extern char lbl_8045986C[];
extern void* lbl_805A03A8;

static inline u8 getIndex() {
    u8 index = fn_800C851C();
    if (index == 0xFF)
        index = 4;
    return index;
}

extern "C" void fn_800D88E0(Entry* self, const Value* value, signed char kind) {
    Entry* entry = &self[getIndex()];
    entry->value = *value;
    entry->kind = kind;

    netReport__FPCce(
        lbl_80459830,
        ((const u64*)value)[0],
        ((u64)value->c << 32) | value->d
    );
    netReport__FPCce(lbl_8045986C, entry->kind);

    self[getIndex()].flag = 0;
    fn_800D0AE0(self);
    fn_80145B98(lbl_805A03A8, 0xFE);
}
