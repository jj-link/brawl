#pragma force_active on
typedef int s32;
typedef unsigned long u32;

extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), u32 elemSize, u32 count);
void __dl__FPv(void* p);
void fn_27_AB510(void* p, s32 n);
}

extern "C" void* fn_27_D2AA4(char* self, s32 n) {
    if (self != 0) {
        __destroy_arr(self + 0xC, (void (*)(void*, int))fn_27_AB510, 0x10, 4);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
