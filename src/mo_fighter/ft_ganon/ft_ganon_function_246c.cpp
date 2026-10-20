#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_109_2154(void*, short);
void* fn_109_21F0(void*, short);
void* fn_109_2230(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_109_246C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_109_2154(static_cast<char*>(object) + 0xdc, memberDeleting);
        fn_109_21F0(static_cast<char*>(object) + 0xc0, memberDeleting);
        fn_109_2230(static_cast<char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
