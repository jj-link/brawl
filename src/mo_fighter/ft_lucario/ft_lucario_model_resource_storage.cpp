void operator delete(void*);
extern "C" void* fn_27_3544C(void*, short);
extern "C" void* fn_27_25740(void*, short);
extern "C" void* fn_27_CC0F0(void*, short);
extern "C" void* __dt__19soPostureModuleImplFv(void*, short);
extern "C" void* fn_27_19FFEC(void*, short);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_118_4614(void*, short);

extern "C" void* fn_118_43F4(void* object, short deleting) {
    if (object != 0) {
        fn_27_3544C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4450(void* object, short deleting) {
    if (object != 0) {
        fn_27_25740(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_27_CC0F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_44BC(void* object, short deleting) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(object) + 0x3C, -1);
        if (object != 0) {
            fn_27_19FFEC(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4530(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x114, -1);
        fn_27_CBDE8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_459C(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_118_4614(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
