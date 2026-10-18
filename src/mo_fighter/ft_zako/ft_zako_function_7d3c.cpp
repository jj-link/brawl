#pragma force_active on
void operator delete(void*);

extern "C" void* fn_126_7CDC(void*, short);

extern "C" void* fn_126_7D3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_7CDC(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
