#pragma force_active on
void operator delete(void*);

extern "C" void fn_121_486C(void*, short);

extern "C" void* fn_121_176C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_121_486C(members + 0x1C, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
