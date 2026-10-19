#pragma force_active on
extern "C" void* fn_27_1A09B4(void*, short);

extern "C" void* fn_98_22DC(void* obj, short deleting) {
    if (obj) {
        fn_27_1A09B4(obj, static_cast<short>(-1));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
