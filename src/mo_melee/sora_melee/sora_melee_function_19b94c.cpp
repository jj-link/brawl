#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned long u32;

extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), u32, u32);
void __dl__FPv(void*);
}

extern "C" void* fn_27_19B94C(u8* self, s32 flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 4);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
