#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void* ptr, void (*dtor)(), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

struct fn_27_Obj {
    u8 unk0[0xC];
    u8 arr[0x24 * 0x30];
};

extern "C" {
void* fn_27_D0130(fn_27_Obj* self, int doDelete) {
    if (self) {
        __destroy_arr((u8*)self + 0xC, fn_27_25290, 0x30, 0x24);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
