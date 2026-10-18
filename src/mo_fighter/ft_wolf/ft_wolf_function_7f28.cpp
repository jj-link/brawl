#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_1A7234(void*, short);

extern "C" void* fn_125_7F28(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A7234(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
