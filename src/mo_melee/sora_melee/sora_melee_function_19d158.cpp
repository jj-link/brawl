#pragma force_active on
typedef void (*DtorFn)(void*, int);

extern "C" {
void __destroy_arr(void*, DtorFn, unsigned long, unsigned long);
void __dt__21soCollisionAttackPartFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_19D158(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 7);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
