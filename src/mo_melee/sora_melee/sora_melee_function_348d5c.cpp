#pragma force_active on
extern "C" {
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* __dt__19soCollisionHitGroupFv(void*, short);
void* __dt__18soCollisionHitPartFv(void*, short);
void* fn_27_37D3C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_348D5C(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__24soCollisionHitModuleImplFv((char*)arg0 + 0x13C, -1);
        if ((unsigned long)((char*)arg0 + 0xF8) != 0) {
            __destroy_arr((char*)arg0 + 0x104, (void (*)(void*, int))__dt__19soCollisionHitGroupFv, 0x38, 1);
        }
        if ((unsigned long)((char*)arg0 + 0x74) != 0) {
            __destroy_arr((char*)arg0 + 0x80, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        }
        if (arg0 != 0) {
            __destroy_arr((char*)arg0 + 0xC, (void (*)(void*, int))__dt__18soCollisionHitPartFv, 0x68, 1);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
