#pragma force_active on
extern "C" {
void* fn_116_726C(void*, short);
void* fn_116_722C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_156B8(void*, short);
}

void operator delete(void*);

extern "C" void* fn_116_18898(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_726C(members + 0x1630C, memberDeleting);
        fn_116_722C(members + 0x162F4, memberDeleting);
        fn_27_C74E8(members + 0x162E0, memberDeleting);
        fn_116_156B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
