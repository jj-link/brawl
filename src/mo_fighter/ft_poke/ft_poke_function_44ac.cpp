#pragma force_active on
extern "C" void* fn_116_3408(void*, short);
void operator delete(void*);

extern "C" void* fn_116_44AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_3408(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
