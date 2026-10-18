#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_10424(void*, short);

extern "C" void* fn_120_2F18(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
