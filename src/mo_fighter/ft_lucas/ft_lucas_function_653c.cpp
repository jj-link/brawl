#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void fn_114_65A8(void* object, short deleting);

extern "C" void* fn_114_653C(void* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(static_cast<char*>(object) + 0x5450, -1);
        fn_114_65A8(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
