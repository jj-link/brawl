#pragma force_active on
void operator delete(void*);

extern "C" void* fn_92_3C48(void*, short);

extern "C" void* fn_92_5C88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_3C48(members + 0x88, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
