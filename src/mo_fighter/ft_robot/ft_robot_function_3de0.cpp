#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3E58(void*, short);
extern "C" void* fn_120_3EF8(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_120_3DE0(void* object, short deleting) {
    if (object != 0) {
        fn_120_3E58(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_120_3EF8(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
