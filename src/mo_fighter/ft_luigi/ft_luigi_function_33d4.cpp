#pragma force_active on
extern "C" void* fn_99_3374(void*, short);

extern "C" void* fn_99_33D4(void* object, short deleting) {
    if (object) {
        fn_99_3374(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
