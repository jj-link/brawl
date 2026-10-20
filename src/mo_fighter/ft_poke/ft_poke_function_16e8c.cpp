#pragma force_active on
extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_19B02C(void*, short);
void operator delete(void*);
}

extern "C" void* fn_116_16E8C(void* object, short deleting) {
    if (object != 0) {
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(object) + 0x5b4, -1);
        fn_27_CC984(static_cast<char*>(object) + 0x570, -1);
        fn_27_4CAA0(static_cast<char*>(object) + 0x4ec, -1);
        fn_27_19B02C(static_cast<char*>(object) + 0x0, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
