#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_1FAC(void*, short);
void* fn_117_1F50(void*, short);
}

extern "C" void* fn_117_463C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_1FAC(storage + 0x20, 0);
        if (object != 0) {
            fn_117_1F50(storage + 0x8, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
