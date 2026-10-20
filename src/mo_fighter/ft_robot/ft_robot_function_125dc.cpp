#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_120_12580(void*, short);
void* fn_120_12540(void*, short);
}

extern "C" void* fn_120_125DC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x20, destroyMember);
        fn_120_12580(storage + 0x10, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_120_12540(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
