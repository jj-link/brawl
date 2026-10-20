#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_B5324(void*, short);
void* fn_117_5DD8(void*, short);
void* fn_117_5E34(void*, short);
}

extern "C" void* fn_117_5D60(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_B5324(members + 0x30, memberDeleting);
        fn_117_5DD8(members + 0x18, memberDeleting);
        fn_117_5E34(members + 0x04, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
