#pragma force_active on
void operator delete(void*);

extern "C" void fn_104_1984C(void*, short);

extern "C" void* fn_104_197EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_1984C(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
