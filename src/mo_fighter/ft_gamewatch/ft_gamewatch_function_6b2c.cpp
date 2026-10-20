#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_3FD0(void*, short);
extern "C" void* fn_107_6BA4(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_107_6B2C(void* object, short deleting) {
    if (object != 0) {
        fn_107_3FD0(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_107_6BA4(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
