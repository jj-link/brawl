#pragma force_active on
void operator delete(void*);

extern "C" void* fn_109_3B50(void*, short);

extern "C" void* fn_109_10AD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x14;
        short memberDeleting = -1;
        fn_109_3B50(member, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
