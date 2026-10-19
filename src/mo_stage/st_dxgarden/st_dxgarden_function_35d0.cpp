#pragma force_active on
extern "C" {
typedef void (*Destructor)(void*, int);
void __destroy_arr(void*, Destructor, unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);
}

extern "C" void* fn_77_35D0(void* object, int shouldDelete)
{
    if (object != 0) {
        __destroy_arr((char*)object + 0x0C, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
