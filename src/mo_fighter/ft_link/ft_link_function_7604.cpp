#pragma force_active on
void operator delete(void*);

extern "C" void* fn_93_75A4(void*, short);

extern "C" void* fn_93_7604(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_75A4(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
