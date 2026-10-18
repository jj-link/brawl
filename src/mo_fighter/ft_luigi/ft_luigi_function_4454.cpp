#pragma force_active on
extern "C" {
void* fn_99_3DA8(void*, short);
void* fn_99_3E2C(void*, short);
void* fn_99_44F0(void*, short);
void* fn_99_454C(void*, short);
void* fn_99_4F64(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_99_4454(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_3DA8(storage + 0xdc4, -1);
        fn_99_3E2C(storage + 0xdb0, -1);
        fn_99_44F0(storage + 0x930, -1);
        fn_99_454C(storage + 0xbc, -1);
        fn_99_4F64(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
