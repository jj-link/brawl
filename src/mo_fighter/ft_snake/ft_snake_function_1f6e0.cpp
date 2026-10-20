#pragma force_active on
extern "C" {
void* fn_122_3EE4(void*, short);
void* fn_122_3F24(void*, short);
void* fn_122_3FD4(void*, short);
}

void operator delete(void*);

extern "C" void* fn_122_1F6E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3EE4(storage + 0xE0, -1);
        fn_122_3F24(storage + 0x30, -1);
        fn_122_3FD4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
