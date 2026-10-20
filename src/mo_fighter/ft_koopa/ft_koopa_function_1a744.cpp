#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_1A7BC(void* p, short flag);
extern "C" void* fn_102_1A7FC(void* object, short deleting);
extern "C" void* fn_102_1A85C(void* object, short deleting);

extern "C" void* fn_102_1A744(void* object, short deleting) {
    if (object != 0) {
        fn_102_1A7BC(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_102_1A7FC(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_102_1A85C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
