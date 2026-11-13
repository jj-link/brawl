#include <types.h>
#pragma force_active on
class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};
class Class_80488228 {
public:
    virtual void fn_802E7A60();
    virtual void fn_802E8284();
    virtual void fn_802F0568();
    virtual void fn_802E83C0();
    virtual void fn_802E7B00();
    u16 f4;
    u16 f6;
    char pad8[0x30];
    int f38;
    char pad3c[0x10];
    void* f4c;
    int f50;
    unsigned int f54;
    void* f58;
    int f5c;
    unsigned int f60;
    void* f64;
    int f68;
    unsigned int f6c;
};
extern SoHeapAllocator* lbl_805A0EB8;
extern void* lbl_805A0EC8;
extern "C" Class_80488228* fn_802E7988(Class_80488228*, void*, int);
extern "C" void* fn_8027EA20(void*, unsigned int, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
struct Pair { int a, b; };
struct E16 { int a, b; Pair c; };
struct EArray { E16* data; int size; unsigned int capacity; };
struct IntArray { int* data; int size; unsigned int capacity; };
inline void copyInts(IntArray* dstArray, int n, const IntArray* srcArray) {
    dstArray->size = n;
    int* dst;
    const int* src;
    src = srcArray->data;
    dst = dstArray->data;
    int i = 0;
    for (; i < n; ++i) dst[i] = src[i];
}
inline void copyE16(EArray* array, int n, const EArray* source) {
    array->size = n;
    int i = 0;
    const E16* src = source->data;
    E16* dst = array->data;
    for (; i < n; ++i) dst[i] = src[i];
}
inline int getCapacity(const unsigned int* p) { return *p & 0x3fffffff; }
extern "C" Class_80488228* fn_802E7B08(Class_80488228* self) {
    Class_80488228* r = (Class_80488228*)lbl_805A0EB8->alloc(0xa0, 0x2f);
    r->f4 = 0xa0;
    if (r != 0) r = fn_802E7988(r, (char*)self + 0x70, self->f38);
    int cap1 = getCapacity(&r->f60);
    if (cap1 < self->f5c) {
        if (!(r->f60 & 0x80000000))
            fn_8027EABC(lbl_805A0EC8, r->f58, cap1 * 4, 0x15);
        r->f58 = fn_8027EA20(lbl_805A0EC8, self->f5c * 4, 0x15);
        r->f60 = self->f5c | (r->f60 & 0x40000000);
    }
    copyInts((IntArray*)&r->f58, self->f5c, (IntArray*)&self->f58);
    int cap2 = getCapacity(&r->f6c);
    if (cap2 < self->f68) {
        if (!(r->f6c & 0x80000000))
            fn_8027EABC(lbl_805A0EC8, r->f64, cap2 * 4, 0x15);
        r->f64 = fn_8027EA20(lbl_805A0EC8, self->f68 * 4, 0x15);
        r->f6c = self->f68 | (r->f6c & 0x40000000);
    }
    copyInts((IntArray*)&r->f64, self->f68, (IntArray*)&self->f64);
    int cap3 = getCapacity(&r->f54);
    if (cap3 < self->f50) {
        if (!(r->f54 & 0x80000000))
            fn_8027EABC(lbl_805A0EC8, r->f4c, cap3 * 16, 0x15);
        r->f4c = fn_8027EA20(lbl_805A0EC8, self->f50 * 16, 0x15);
        r->f54 = self->f50 | (r->f54 & 0x40000000);
    }
    copyE16((EArray*)&r->f4c, self->f50, (EArray*)&self->f4c);
    return r;
}