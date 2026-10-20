#pragma force_active on
typedef unsigned char u8;

struct Pair {
    int a, b;
};

struct Params {
    Pair p[4];
};

class VObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8(float) = 0;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
u8* fn_16_1FC0(void*);
extern Params lbl_16_data_3320;
extern int lbl_16_data_3488[4][4];
extern char lbl_16_data_3310[];
extern const Params lbl_16_rodata_140;
extern const float lbl_16_rodata_128;
void fn_16_25A0(u8*, const Params*, int, void*, int, void*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void* fn_16_49F0(u8*, void*, void*);
void* fn_16_6C64(void*);
void fn_16_23D0(u8*, void*, int, void*, void*, void*, void*, void*, void*);
}

extern "C" u8* fn_16_1CB0(
    void* a, int b, void* c, void* d, void* e, void* f,
    void* g, void* h, void* i, void* j, void* k
) {
    u8* obj = (u8*)__nw__FUlQ25Heaps8HeapType(0x480, 0x2a);
    if (obj)
        obj = fn_16_1FC0(obj);

    Params params = lbl_16_data_3320;
    params.p[0].a = lbl_16_data_3488[0][b];
    params.p[1].a = lbl_16_data_3488[1][b];
    params.p[2].a = lbl_16_data_3488[2][b];
    params.p[3].a = lbl_16_data_3488[3][b];
    fn_16_25A0(obj, &params, 4, c, 1, f);

    void* heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
    *(void**)(obj + 0x8c) = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(
        heap, 0, 2, *(void**)(*(u8**)(obj + 0x40) + 0x10));
    *(void**)(obj + 0x90) = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(
        heap, 0, 4, *(void**)(*(u8**)(obj + 0x48) + 0x10));

    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        *(void**)(obj + 0x8c),
        *(void**)(*(u8**)(obj + 0x44) + 0x10),
        lbl_16_data_3310);

    (*(VObj**)(*(u8**)(*(u8**)(obj + 0x44) + 0x14) + 0x18))
        ->v8(lbl_16_rodata_128);

    fn_16_25A0(obj, &lbl_16_rodata_140, 8, d, 0, f);

    if (i)
        *(void**)(obj + 0x408) = fn_16_6C64(fn_16_49F0(obj, i, f));

    fn_16_23D0(obj, a, b, e, f, g, h, j, k);
    return obj;
}
