#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);

inline void* operator new(unsigned long, void* p) { return p; }

struct Flags {
    u8 pad;
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 rest : 4;
};

struct Output {
    u16 a, b;
    s16 c, d;
    u8 e, f;
    s16 g, h;
    union { u16 i; Flags fl; };
    u16 j;

    bool any() { return fl.b4 || fl.b5 || fl.b6; }

    Output(char* src, int enabled) {
        a = *(u16*)(src + 0);
        b = *(u16*)(src + 2);
        c = *(s16*)(src + 4);
        d = *(s16*)(src + 6);
        e = 0;
        f = 0;
        g = -1;
        h = -1;
        i = *(u16*)(src + 12);
        j = *(u16*)(src + 14);
        if (!enabled) fl.b4 = 1;
        if (!any()) fl.b4 = 1;
    }
};

extern "C" void* fn_801107CC(void*, u32 count, char* src, int enabled) {
    Output* result = (Output*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(15, count * 18);
    Output* dst = result;
    for (u32 n = 0; n < count; ++n, ++dst, src += 16) {
        new (dst) Output(src, enabled);
    }
    return result;
}
