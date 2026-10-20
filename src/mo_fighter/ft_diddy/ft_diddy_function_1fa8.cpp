#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_115_202C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_115_28E4(void*, short);
}

extern "C" void* fn_115_1FA8(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short destroy = -1;
        fn_115_202C(members + 0x24AE4, destroy);
        fn_27_C74E8(members + 0x24AD4, destroy);
        fn_115_28E4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
