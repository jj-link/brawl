#pragma force_active on
extern "C" void* fn_110_408C(void* object, short deleting);
extern "C" void* fn_110_52FC(void* object, short deleting);
extern "C" void* fn_27_19E99C(void* object, short deleting);

extern "C" void* fn_110_5284(void* object, short deleting) {
    if (object != 0) {
        fn_110_408C(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_110_52FC(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
