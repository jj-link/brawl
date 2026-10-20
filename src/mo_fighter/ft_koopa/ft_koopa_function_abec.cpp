#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_AA54(void*, short);
extern "C" void* fn_102_AB8C(void*, short);

extern "C" void* fn_102_ABEC(void* object, short deleting) {
    if (object != 0) {
        fn_102_AB8C(static_cast<unsigned char*>(object) + 0x17c, -1);
        if (object != 0) {
            fn_102_AA54(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
