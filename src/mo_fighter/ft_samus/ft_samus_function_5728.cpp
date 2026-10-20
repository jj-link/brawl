#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_94_57A0(void*, short);

extern "C" void* fn_94_5728(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_94_57A0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
