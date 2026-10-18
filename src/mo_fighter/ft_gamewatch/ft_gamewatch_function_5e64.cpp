#pragma force_active on
void operator delete(void*);

extern "C" void* fn_107_5EC4(void*, short);

extern "C" void* fn_107_5E64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_5EC4(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
