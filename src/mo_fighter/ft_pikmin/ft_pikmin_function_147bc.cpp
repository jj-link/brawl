#pragma force_active on
extern "C" {
void* fn_113_D68(void*, short);
void* fn_113_E04(void*, short);
void* fn_113_E44(void*, short);
}

extern "C" void* fn_113_147BC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_113_D68(storage + 0xcc, destroyMember);
        fn_113_E04(storage + 0xb0, destroyMember);
        fn_113_E44(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
