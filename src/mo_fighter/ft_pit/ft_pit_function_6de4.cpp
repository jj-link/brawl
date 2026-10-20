#pragma force_active on
void operator delete(void*);

extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_19ADE4(void*, short);
}

extern "C" void* fn_112_6DE4(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(object) + 0x54c, destroy);
        fn_27_CC984(static_cast<char*>(object) + 0x508, destroy);
        fn_27_4CAA0(static_cast<char*>(object) + 0x484, destroy);
        fn_27_19ADE4(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
