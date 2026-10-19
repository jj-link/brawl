#pragma force_active on
extern "C" void __destroy_arr(void* arr, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dt__18soCollisionHitPartFv(void* obj, int param);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_56_57DC(void* obj, int freeFlag) {
    if (obj != 0) {
        __destroy_arr((char*)obj + 0xC, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (freeFlag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
