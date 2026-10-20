#pragma force_active on
extern "C" {
void* fn_27_1A262C(void*, short);
void* fn_112_4AFC(void*, short);
void* fn_112_4B3C(void*, short);
}

void operator delete(void*);

extern "C" void* fn_112_4A74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_112_4AFC(storage + 0x24, 0);
        }
        fn_112_4B3C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
