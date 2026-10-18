#pragma force_active on
extern "C" {
void* fn_99_1944(void*, short);
void* fn_99_1D24(void*, short);
void* fn_99_1DC0(void*, short);
void* fn_99_1EF8(void*, short);
void* fn_27_125E20(void*, short);
}

extern "C" void* fn_99_18A4(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_1944(storage + 0xE14C, -1);
        fn_99_1D24(storage + 0xDC94, -1);
        fn_99_1DC0(storage + 0xDC58, -1);
        fn_99_1EF8(storage + 0x194, -1);
        fn_27_125E20(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
