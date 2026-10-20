#pragma force_active on
extern "C" {
void* fn_113_D68(void* object, short deleting);
void* fn_113_E04(void* object, short count);
void* fn_113_E44(void* object, short count);
}

extern "C" void* fn_113_146CC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_113_D68(storage + 0xCC, destroyMember);
        fn_113_E04(storage + 0xB0, destroyMember);
        fn_113_E44(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
