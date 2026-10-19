#pragma force_active on
extern "C" void* fn_121_7CD0(void* object, short deleting);
extern "C" void fn_121_5F68(void* object, short n);

extern "C" void* fn_121_7D2C(void* object, short deleting) {
    if (object != 0) {
        fn_121_7CD0(static_cast<unsigned char*>(object) + 8, -1);
        fn_121_5F68(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
