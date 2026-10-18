#pragma force_active on
void operator delete(void*);

extern "C" void fn_126_33D0(void*, short);

extern "C" void* fn_126_3370(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_126_33D0(members + 12, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
