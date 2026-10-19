#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_7B5C(void*, short);

extern "C" void* fn_126_7C1C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_126_7B5C(static_cast<unsigned char*>(object) + 4,
                        static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
