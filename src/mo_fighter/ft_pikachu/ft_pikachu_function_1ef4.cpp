#pragma force_active on
extern "C" void fn_27_1362C(void*, short);

extern "C" void* fn_98_1EF4(void* obj, short deleting) {
    if (obj) {
        fn_27_1362C(obj, static_cast<short>(0));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
