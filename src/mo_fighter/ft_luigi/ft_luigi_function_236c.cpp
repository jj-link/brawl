#pragma force_active on
extern "C" {
void* fn_99_20E0(void*, short);
void* fn_99_217C(void*, short);
void* fn_99_21BC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_99_236C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_20E0(storage + 0xdc, destroyMember);
        fn_99_217C(storage + 0xc0, destroyMember);
        fn_99_21BC(storage + 0x14, destroyMember);
        if (object) fn_27_C7770(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
