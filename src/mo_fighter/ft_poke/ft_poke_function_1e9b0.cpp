#pragma force_active on
extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_19BB94(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_1E9B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x414, -1);
        fn_27_CC984(storage + 0x3d0, -1);
        fn_27_4CAA0(storage + 0x34c, -1);
        fn_27_19BB94(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
