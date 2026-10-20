#pragma force_active on
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void fn_27_CC984(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_19B94C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_1EE40(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x274, -1);
        fn_27_CC984(storage + 0x230, -1);
        fn_27_4CAA0(storage + 0x1ac, -1);
        fn_27_19B94C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
