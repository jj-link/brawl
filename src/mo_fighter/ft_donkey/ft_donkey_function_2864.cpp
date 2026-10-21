#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_2204(void*, short);
void* fn_92_22A0(void*, short);
void* fn_92_22E0(void*, short);
void* fn_92_28FC(void*, short);
void fn_27_1A6B04(void*, short);
}

extern "C" void* fn_92_2864(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_2204(members + 0xA8C, memberDeleting);
        fn_92_22A0(members + 0xA70, memberDeleting);
        fn_92_22E0(members + 0x9C4, memberDeleting);
        fn_92_28FC(members + 0x4E0, memberDeleting);
        if (object != 0) {
            fn_27_1A6B04(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
