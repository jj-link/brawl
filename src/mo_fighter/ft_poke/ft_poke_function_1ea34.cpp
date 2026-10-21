#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_116_6C30(void*, short);
void* fn_116_6C9C(void*, short);
void* fn_116_6CF8(void*, short);
void* fn_116_6D54(void*, short);
void* fn_116_16FC4(void*, short);
void* fn_116_6E0C(void*, short);
}

extern "C" void* fn_116_1EA34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short minus_one = -1;
        fn_27_13C90(storage + 0x224, minus_one);
        fn_116_6C30(storage + 0x1e8, minus_one);
        fn_27_21038(storage + 0x1d8, minus_one);
        fn_116_6C9C(storage + 0x1b8, minus_one);
        fn_116_6CF8(storage + 0x198, minus_one);
        fn_116_6D54(storage + 0x160, minus_one);
        fn_116_16FC4(storage + 0xc4, minus_one);
        fn_116_6E0C(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
