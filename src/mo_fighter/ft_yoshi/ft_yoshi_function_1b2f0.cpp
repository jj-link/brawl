#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_38A4(void*, short);
extern "C" void* fn_95_1B360(void*, short);

extern "C" void* fn_95_1B2F0(void* object, short deleting) {
    if (object != 0) {
        fn_95_38A4(static_cast<unsigned char*>(object) + 0x1800, -1);
        fn_95_1B360(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
