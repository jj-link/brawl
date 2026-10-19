#pragma force_active on
extern "C" void* fn_27_A0C74(void*, short);

extern "C" void* fn_98_2214(void* obj, short deleting) {
    if (obj) {
        fn_27_A0C74(obj, static_cast<short>(-1));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
