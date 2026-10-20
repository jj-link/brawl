#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __dt__25soCollisionAttackAbsoluteFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

u8* fn_27_D2578(u8* self, int deleting) {
    if (self) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))__dt__25soCollisionAttackAbsoluteFv, 0x68, 1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
