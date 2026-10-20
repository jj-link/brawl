#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void __dt__21soCollisionAttackPartFv(void* p, int flags);

void* fn_27_19CA80(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
