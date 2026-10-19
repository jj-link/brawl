#pragma force_active on
typedef unsigned int u32;

extern "C" void* fn_40_16DD8();
extern "C" void* fn_40_17398(void* self);
extern "C" void fn_40_1643C(void* self, u32 value);

extern "C" void fn_40_64F4(void* unused, u32 value) {
    fn_40_1643C(fn_40_17398(fn_40_16DD8()), value);
}
