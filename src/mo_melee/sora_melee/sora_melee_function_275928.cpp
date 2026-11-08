#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void* fn_27_27C0C4(void*, int);
extern unsigned char lbl_27_data_5A028[];

void* __dt__8grMadeinFv(void* self, int deleteFlag) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x168);
        *(void**)((char*)self + 0x3C) = lbl_27_data_5A028;
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        ptr = *(void**)((char*)self + 0x164);
        if (ptr != 0 && ptr != 0) {
            __dl__FPv(ptr);
        }
        ptr = *(void**)((char*)self + 0x15C);
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        ptr = *(void**)((char*)self + 0x160);
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        fn_27_27C0C4(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
