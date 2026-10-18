#pragma force_active on
void operator delete(void*);
extern "C" void fn_117_44C8(void*, short);

extern "C" void* fn_117_1478C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_44C8(storage + 0x38, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
