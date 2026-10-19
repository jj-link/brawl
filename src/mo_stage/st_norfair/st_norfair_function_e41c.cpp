#pragma force_active on
extern "C" {

void __dt__21soCollisionAttackPartFv(void* p, int flags);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);

void* fn_54_E41C(void* ptr, int n) {
    void* ret = ptr;
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 5);
        if (n > 0) {
            __dl__FPv(ptr);
        }
    }
    return ret;
}

}
