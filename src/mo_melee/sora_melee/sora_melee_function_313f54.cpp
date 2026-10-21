#pragma force_active on
extern "C" {
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* __dt__19soCollisionHitGroupFv(void*, short);
void* __dt__18soCollisionHitPartFv(void*, short);
void* fn_27_37D3C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_313F54(void* self, int flag) {
    if (self) {
        __dt__24soCollisionHitModuleImplFv((char*)self + 0x274, -1);
        if ((char*)self + 0x230) {
            __destroy_arr((char*)self + 0x23C, (void (*)(void*, int))__dt__19soCollisionHitGroupFv, 0x38, 1);
        }
        if ((char*)self + 0x1AC) {
            __destroy_arr((char*)self + 0x1B8, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        }
        if (self) {
            __destroy_arr((char*)self + 0xC, (void (*)(void*, int))__dt__18soCollisionHitPartFv, 0x68, 4);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
