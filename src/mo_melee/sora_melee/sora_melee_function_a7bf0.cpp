#pragma force_active on
typedef unsigned int u32;

extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" u32 fn_27_22B3B8(void*, void*, void*);
extern "C" const float lbl_27_rodata_D28;

struct Self {
    char pad[0x10];
    void* field_10;
};

struct Local {
    u32 x;
    float y;
};

extern "C" float fn_27_A7BF0(Self* self) {
    if (!lbl_27_bss_5780) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (p)
            p = fn_27_22A914(p);
        lbl_27_bss_5780 = p;
    }

    Local local;
    if (fn_27_22B3B8(lbl_27_bss_5780, self->field_10, &local) == 1)
        return local.y;
    return lbl_27_rodata_D28;
}
