#pragma force_active on
extern "C" {
void* fn_99_3374(void*, short);
void* fn_99_33D4(void*, short);
}

extern "C" void* fn_99_3308(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_3374(static_cast<unsigned char*>(object) + 0x1F54, destroyMember);
        fn_99_33D4(static_cast<unsigned char*>(object) + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
