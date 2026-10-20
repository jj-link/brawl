#pragma force_active on
extern "C" {
void* fn_113_D68(void*, short);
void* fn_113_E04(void*, short);
void* fn_113_E44(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_14744(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_113_D68(storage + 0xCC, destroyMember);
        fn_113_E04(storage + 0xB0, destroyMember);
        fn_113_E44(storage + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
