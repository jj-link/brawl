#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;
typedef int s32;

struct ElemA {
    f32 v[8];
    ElemA& operator=(const ElemA& o) {
        v[0] = o.v[0]; v[1] = o.v[1]; v[2] = o.v[2]; v[3] = o.v[3];
        v[4] = o.v[4]; v[5] = o.v[5]; v[6] = o.v[6]; v[7] = o.v[7];
        return *this;
    }
};

struct ElemB {
    f32 a;
    f32 b;
    s32 c;
    u16 d;
    u8 e;
    u8 f;
    f32 g;
    ElemB& operator=(const ElemB& o) {
        a = o.a; b = o.b; c = o.c; d = o.d; e = o.e; f = o.f; g = o.g;
        return *this;
    }
};

struct Info {
    s32 w[7];
};

struct Buf {
    s32 unk0;
    u16 count;
    u16 capacity;
    u16 unk8;
    u16 unkA;
    Info info;
    u8 data[1];
};

extern "C" void fn_802DA190(Buf* dst, Buf* src) {
    dst->unk8 = src->unk8;
    ElemA* dA = (ElemA*)(((unsigned long)dst + 0x37) & ~0xF);
    ElemB* dB = (ElemB*)((u8*)dA + (dst->capacity << 5));
    ElemA* sA = (ElemA*)(((unsigned long)src + 0x37) & ~0xF);
    dst->unkA = src->unkA;
    dst->info = src->info;
    dst->count = src->count;
    ElemB* sB = (ElemB*)((u8*)sA + (src->capacity << 5));
    for (int i = 0; i < src->count; i++) {
        *dA++ = *sA++;
        *dB++ = *sB++;
    }
}
