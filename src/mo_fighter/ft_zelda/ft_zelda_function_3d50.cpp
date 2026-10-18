#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_3DB0(void*, short);

extern "C" void* fn_104_3D50(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x38;
        short memberDeleting = -1;
        fn_104_3DB0(member, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
