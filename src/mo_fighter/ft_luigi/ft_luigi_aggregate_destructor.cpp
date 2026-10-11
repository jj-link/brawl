extern "C" {
void* fn_99_EECC(void*, short);
void* fn_99_EF38(void*, short);
void* fn_99_EFC4(void*, short);
void* fn_99_F050(void*, short);
void* fn_99_F0DC(void*, short);
}

// The five embedded components are destroyed in reverse construction order.
extern "C" void* fn_99_EE3C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_99_EECC(storage + 0x4b0, -1);
        fn_99_EF38(storage + 0x384, -1);
        fn_99_EFC4(storage + 0x258, -1);
        fn_99_F050(storage + 0x12c, -1);
        fn_99_F0DC(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
