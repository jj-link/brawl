#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void* fn_99_49E4(void* member, short deleteFlag);
}

// Destroy the member module at 0x2d0, then the embedded base, before the object itself.
// Only positive flags delete; the sign-extended flags select member/base deletion mode.
extern "C" void* fn_99_496C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int memberDeleteFlag = -1;
        fn_27_1A1B88(storage + 0x2d0, memberDeleteFlag);
        if (object) {
            int baseDeleteFlag = 0;
            fn_99_49E4(object, baseDeleteFlag);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
