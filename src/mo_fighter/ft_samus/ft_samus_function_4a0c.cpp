#pragma force_active on
void operator delete(void*);

extern "C" void fn_94_4A6C(void*, short);

extern "C" void* fn_94_4A0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_4A6C(member + 0xC, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
