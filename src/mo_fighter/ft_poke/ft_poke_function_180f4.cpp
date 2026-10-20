#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
void fn_27_12DCA8(void*);
void* fn_116_17F48();
void fn_27_372664(void*, void*);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_368B30(void*);

void fn_116_180F4(void* self) {
    fn_27_12DCA8(self);
    void* result = fn_116_17F48();
    fn_27_372664(result, *(void**)((char*)self + 0x60));
    if (lbl_27_bss_F0 == 0) {
        void* ptr = operator new(0x4c, Heaps::System);
        if (ptr) {
            ptr = fn_27_5BCD0(ptr);
        }
        lbl_27_bss_F0 = ptr;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        fn_27_368B30((unsigned char*)self + 0x162F4);
    }
}
}
