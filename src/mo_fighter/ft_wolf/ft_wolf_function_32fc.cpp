#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_336C(void*, short);
extern "C" void* fn_125_6130(void*, short);

extern "C" void* fn_125_32FC(void* object, short deleting) {
    if (object != 0) {
        fn_125_336C(static_cast<unsigned char*>(object) + 8, -1);
        fn_125_6130(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
