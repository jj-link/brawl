#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct Object {
    u8 pad0[6];
    u16 version;
    u8 pad8[0x20];
    void* data;
};

struct Entry {
    u32 value;
    u32 field4;
    u32 field8;
    u8 fieldC;
    u8 fieldD;
};

struct Output {
    u32 value;
    u32 field4;
    u32 field8;
    u32 fieldC;
    bool field10;
};

extern "C" u64 fn_801C8010();
extern "C" Entry* fn_801D3698(u8, u32, void*);

extern "C" int fn_801C75A8(Object* __restrict self, void* unused, Output* out) {
    u64 v = fn_801C8010();
    u8* bytes = (u8*)&v;
    Entry* p = fn_801D3698(bytes[0], *(u32*)(bytes + 4), self->data);

    if (p == 0) {
        return 0;
    }

    out->value = p->value;
    out->field4 = p->field4;
    out->fieldC = p->fieldC;
    out->field8 = p->field8;

    if (self->version >= 0x103) {
        out->field10 = p->fieldD != 0;
    } else {
        out->field10 = false;
    }

    return 1;
}
