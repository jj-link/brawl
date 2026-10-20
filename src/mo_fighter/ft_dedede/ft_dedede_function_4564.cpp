#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_ABB8(void*, short);
void* fn_117_45DC(void*, short);
void* fn_117_463C(void*, short);
}

extern "C" void* fn_117_4564(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_ABB8(members + 0xE0, memberDeleting);
        fn_117_45DC(members + 0x30, memberDeleting);
        fn_117_463C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
