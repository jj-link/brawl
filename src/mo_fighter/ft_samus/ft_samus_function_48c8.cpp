#pragma force_active on
void operator delete(void*);

extern "C" void* fn_94_1EB8(void*, short);

extern "C" void* fn_94_48C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = 0;
        fn_94_1EB8(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
