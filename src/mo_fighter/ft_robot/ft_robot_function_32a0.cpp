#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3310(void*, short);
extern "C" void* fn_120_38FC(void*, short);

extern "C" void* fn_120_32A0(void* object, short deleting) {
    if (object != 0) {
        fn_120_3310(static_cast<unsigned char*>(object) + 8, -1);
        fn_120_38FC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
