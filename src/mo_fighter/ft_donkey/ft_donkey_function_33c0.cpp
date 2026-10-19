#pragma force_active on
extern "C" void* fn_92_3430(void* object, short deleting);
extern "C" void* fn_92_47E4(void* object, short deleting);

extern "C" void* fn_92_33C0(void* object, short deleting) {
    if (object != 0) {
        fn_92_3430(static_cast<unsigned char*>(object) + 0x7F58, -1);
        fn_92_47E4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
