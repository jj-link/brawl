#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void fn_27_CDA70(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_325974(char* self, int flag) {
    if (self) {
        fn_27_93100(self + 0x30, -1);
        if ((unsigned long)(self + 0x10) != 0) {
            __destroy_arr(self + 0x1C, fn_27_CDA70, 0x10, 1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
