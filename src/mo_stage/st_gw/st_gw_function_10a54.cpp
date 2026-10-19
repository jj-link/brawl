#pragma force_active on
extern "C" {
typedef void (*Dtor)(void*, int);

void __dt__21soCollisionAttackPartFv(void*, int);
void __destroy_arr(void*, Dtor, unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_63_10A54(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
}
