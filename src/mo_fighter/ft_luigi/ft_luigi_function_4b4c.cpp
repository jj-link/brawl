#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_99_4BC4(void*, short);

extern "C" void* fn_99_4B4C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_1A1E70(storage + 0x190, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_99_4BC4(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
