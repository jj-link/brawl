#pragma force_active on
extern "C" {
void* fn_27_1A241C(void*, short);
void* fn_97_4E18(void*, short);
void fn_97_1FCC(void*, short);
void* fn_97_4E58(void*, short);
}

void operator delete(void*);

extern "C" void* fn_97_4D7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_97_4E18(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_97_1FCC(storage + 0x20, 0);
            fn_97_4E58(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
