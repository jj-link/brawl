#pragma force_active on
extern "C" {
void* fn_109_2154(void*, short);
void* fn_109_21F0(void*, short);
void* fn_109_2230(void*, short);
void* fn_27_C7770(void*, short);
}

void operator delete(void*);

extern "C" void* fn_109_10310(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_109_2154(members + 0xdc, memberDeleting);
        fn_109_21F0(members + 0xc0, memberDeleting);
        fn_109_2230(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
