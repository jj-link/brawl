#pragma force_active on
extern "C" {
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_F844(void*, short);
void* fn_27_C7770(void*, short);
}

void operator delete(void*);

extern "C" void* fn_116_22EA0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2164(members + 0x50, memberDeleting);
        fn_116_2200(members + 0x34, memberDeleting);
        fn_116_F844(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
