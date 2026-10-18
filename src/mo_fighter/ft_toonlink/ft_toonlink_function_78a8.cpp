#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_3A9380(void*, short);

extern "C" void* fn_121_78A8(void* object, short deleting) {
    if (object != 0) {
        fn_27_3A9380(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
