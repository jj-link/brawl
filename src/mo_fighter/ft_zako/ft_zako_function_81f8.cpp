#pragma force_active on
void operator delete(void*);

extern "C" void* fn_126_8198(void*, short);

extern "C" void* fn_126_81F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_8198(member + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
