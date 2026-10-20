#pragma force_active on
extern "C" {
void* fn_99_8F50(void*, short);
void* fn_99_4378(void*, short);
void* fn_99_43E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_99_4300(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_8F50(storage + 0xE0, destroyMember);
        fn_99_4378(storage + 0x30, destroyMember);
        fn_99_43E8(object, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
