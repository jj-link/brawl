#pragma force_active on

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_92_67C8(void*, short);
void* fn_92_6834(void*, short);
void* fn_92_6890(void*, short);
void* fn_92_68EC(void*, short);
void* fn_92_6948(void*, short);
void* fn_92_69A4(void*, short);
void operator delete(void*);
}

extern "C" void* fn_92_6714(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x2B4, -1);
        fn_92_67C8(storage + 0x278, -1);
        fn_27_21038(storage + 0x268, -1);
        fn_92_6834(storage + 0x248, -1);
        fn_92_6890(storage + 0x228, -1);
        fn_92_68EC(storage + 0x1F0, -1);
        fn_92_6948(storage + 0xC4, -1);
        fn_92_69A4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
