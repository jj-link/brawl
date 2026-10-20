#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_4904(void*, short);
extern "C" void* fn_117_49A4(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_117_488C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_4904(members + 0x85c, memberDeleting);
        fn_117_49A4(members + 0x19c, memberDeleting);
        fn_27_19E99C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
