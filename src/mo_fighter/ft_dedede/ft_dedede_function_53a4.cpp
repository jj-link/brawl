#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_5410(void*, short);
extern "C" void* fn_117_5470(void*, short);

extern "C" void* fn_117_53A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_5410(members + 0x24, memberDeleting);
        fn_117_5470(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
