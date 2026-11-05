#pragma force_active on

extern "C" {
void fn_27_5BC74();
void* fn_27_4FAB4(void*);
void fn_27_4FE14(void*, void*, void*, void*, void*);
void* fn_27_C152C(void*);
void fn_27_C673C();
void fn_27_57C88(void*, int, int);
void fn_27_C2CA8(void*, int, int);
void* fn_27_A068C(void*);
void fn_27_A0B08(void*);
void* fn_27_64A90(void*);
void* fn_27_5BCD0(void*);

extern void* lbl_27_bss_F0;
extern void* lbl_27_bss_B8;
extern void* lbl_27_bss_2BD8;
extern void* lbl_27_bss_D0;
extern void* lbl_27_bss_2BEC;
extern void* lbl_27_bss_2B78;
extern void* lbl_27_bss_F8;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
}

extern "C" void fn_27_3AD0(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_27_5BC74();
    if (lbl_27_bss_F0 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (ptr != 0) {
            ptr = fn_27_5BCD0(ptr);
        }
        lbl_27_bss_F0 = ptr;
    }
    if (lbl_27_bss_B8 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
        if (ptr != 0) {
            ptr = fn_27_4FAB4(ptr);
        }
        lbl_27_bss_B8 = ptr;
    }
    fn_27_4FE14(lbl_27_bss_B8, arg0, arg1, arg2, arg3);
    if (lbl_27_bss_2BD8 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0xa4, 2);
        if (ptr != 0) {
            ptr = fn_27_C152C(ptr);
        }
        lbl_27_bss_2BD8 = ptr;
    }
    fn_27_C673C();
    fn_27_57C88(&lbl_27_bss_D0, 0x80, 2);
    fn_27_C2CA8(&lbl_27_bss_2BEC, 0xbb8, 2);
    if (lbl_27_bss_2B78 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0x140, 2);
        if (ptr != 0) {
            ptr = fn_27_A068C(ptr);
        }
        lbl_27_bss_2B78 = ptr;
    }
    fn_27_A0B08(lbl_27_bss_2B78);
    if (lbl_27_bss_F8 == 0) {
        void* ptr = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (ptr != 0) {
            ptr = fn_27_64A90(ptr);
        }
        lbl_27_bss_F8 = ptr;
    }
}
