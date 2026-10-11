void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_27_6880C(void*, short);
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_118_43B4(void*, short);

extern "C" void* fn_118_420C(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_426C(void* object, short deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_42CC(void* object, short deleting) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4328(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x20, -1);
        if (storage + 0x10 != 0) {
            fn_118_43B4(storage + 0x10, 0);
        }
        if (object != 0) {
            fn_118_43B4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_43B4(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
