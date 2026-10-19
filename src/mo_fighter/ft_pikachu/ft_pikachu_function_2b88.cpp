#pragma force_active on
extern "C" void* fn_27_5BFA0(void*, short);

extern "C" void* fn_98_2B88(void* obj, short deleting) {
    if (obj) {
        fn_27_5BFA0(obj, static_cast<short>(-1));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
