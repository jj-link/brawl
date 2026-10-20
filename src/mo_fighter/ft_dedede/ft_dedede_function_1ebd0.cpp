#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_93100(void*, short);
void* fn_27_19EB34(void*, short);
void* fn_27_1A4E94(void*, short);
}

extern "C" void* fn_117_1EBD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_93100(members + 0x30, memberDeleting);
        fn_27_19EB34(members + 0x10, memberDeleting);
        fn_27_1A4E94(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
