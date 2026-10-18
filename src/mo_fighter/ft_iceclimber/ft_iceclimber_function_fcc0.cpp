#pragma force_active on
void operator delete(void*);

extern "C" void fn_105_FC64(void*, short);

extern "C" void* fn_105_FCC0(void* object, short deleting) {
    if (object != 0) {
        fn_105_FC64(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
