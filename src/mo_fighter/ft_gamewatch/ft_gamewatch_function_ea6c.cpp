#pragma force_active on
void operator delete(void*);

extern "C" void fn_107_EA0C(void*, short);

extern "C" void* fn_107_EA6C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_EA0C(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
