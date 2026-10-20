#pragma force_active on
extern "C" {
void* fn_99_1F7C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_99_2834(void*, short);
}

extern "C" void* fn_99_1EF8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_1F7C(storage + 0xC4F8, -1);
        fn_27_C74E8(storage + 0xC4E8, -1);
        fn_99_2834(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
