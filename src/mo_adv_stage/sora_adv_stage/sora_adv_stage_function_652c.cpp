#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_40_16DD8();
void* fn_40_17398(void* self);
void fn_40_16444(void* self, u32 value);
}

extern "C" void fn_40_652C(void* self, u32 value) {
    fn_40_16444(fn_40_17398(fn_40_16DD8()), value);
}
