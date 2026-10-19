#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_AA00(void*, short);

extern "C" void* fn_119_AAC0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_119_AA00(static_cast<unsigned char*>(object) + 4,
                        static_cast<short>(-1));
        }

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
