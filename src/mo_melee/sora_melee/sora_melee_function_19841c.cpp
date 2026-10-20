#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_137EC(void*, int);

extern "C" {
void* fn_27_19841C(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xC, fn_27_137EC, 0x2C, 2);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
