#pragma force_active on
extern "C" void* fn_27_3544C(void*, short);

extern "C" void* fn_99_4074(void* object, short deleting) {
    if (object) {
        fn_27_3544C(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
