#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_9640(void*, short);
extern "C" void* fn_102_43D4(void*, short);
extern "C" void* fn_102_4444(void*, short);

extern "C" void* fn_102_435C(void* object, short deleting) {
    if (object != 0) {
        fn_102_9640(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_102_43D4(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_102_4444(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
