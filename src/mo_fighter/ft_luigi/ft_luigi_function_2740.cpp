#pragma force_active on
extern "C" {
void* fn_99_20E0(void*, short);
void* fn_99_217C(void*, short);
void* fn_99_21BC(void*, short);
void* fn_99_27D8(void*, short);
void fn_27_1A5DD0(void*, short);
}

extern "C" void* fn_99_2740(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_20E0(storage + 0x9cc, destroyMember);
        fn_99_217C(storage + 0x9b0, destroyMember);
        fn_99_21BC(storage + 0x904, destroyMember);
        fn_99_27D8(storage + 0x480, destroyMember);
        if (object) fn_27_1A5DD0(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
