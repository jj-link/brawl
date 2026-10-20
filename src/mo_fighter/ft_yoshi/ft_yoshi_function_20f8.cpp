#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_217C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_95_2A34(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_20F8(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_95_217C(members + 0x20538, memberDeleting);
        fn_27_C74E8(members + 0x20528, memberDeleting);
        fn_95_2A34(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
