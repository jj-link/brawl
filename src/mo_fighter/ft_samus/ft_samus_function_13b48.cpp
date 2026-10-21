#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_2234(void*, short);
void* fn_94_13BE0(void*, short);
void* fn_27_1A61E0(void*, short);
}

extern "C" void* fn_94_13B48(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_2158(members + 0x9EC, memberDeleting);
        fn_94_21F4(members + 0x9D0, memberDeleting);
        fn_94_2234(members + 0x924, memberDeleting);
        fn_94_13BE0(members + 0x490, memberDeleting);
        if (object != 0) {
            fn_27_1A61E0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
