#pragma force_active on
extern "C" void* fn_27_C96C0(void*, short);

extern "C" void* fn_99_5BC8(void* object, short deleting) {
    if (object) {
        fn_27_C96C0(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
