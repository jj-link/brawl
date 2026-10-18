#pragma force_active on
void operator delete(void*);

extern "C" void fn_104_57B4(void*, short);

extern "C" void* fn_104_5754(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_57B4(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
