#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void* fn_99_478C(void* object, short flag);
}

extern "C" void* fn_99_4714(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x48c, -1);
        if (object) {
            fn_99_478C(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
