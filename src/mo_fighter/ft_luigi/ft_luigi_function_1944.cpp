extern "C" {
void* fn_99_19FC(void*, short);
void* fn_99_1ABC(void*, short);
void* fn_99_1B18(void*, short);
void* fn_99_1B74(void*, short);
void* fn_99_1BD0(void*, short);
void* fn_99_1C2C(void*, short);
void* fn_99_1C88(void*, short);
void* fn_99_1CE4(void*, short);
}

extern "C" void* fn_99_1944(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_19FC(storage + 0x84, -1);
        fn_99_1ABC(storage + 0x70, -1);
        fn_99_1B18(storage + 0x5C, -1);
        fn_99_1B74(storage + 0x48, -1);
        fn_99_1BD0(storage + 0x34, -1);
        fn_99_1C2C(storage + 0x20, -1);
        fn_99_1C88(storage + 0x8, -1);
        fn_99_1CE4(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
