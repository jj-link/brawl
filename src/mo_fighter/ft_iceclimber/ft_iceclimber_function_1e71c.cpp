#pragma force_active on
extern "C" void* fn_27_1A4980(void*, short);

extern "C" void* fn_105_1E71C(void* object, short deleting) {
    if (object) {
        fn_27_1A4980(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
