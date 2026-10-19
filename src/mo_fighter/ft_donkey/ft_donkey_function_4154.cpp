#pragma force_active on
extern "C" void* fn_92_1F64(void* ptr, short count);
extern "C" void* fn_92_1FC0(void* object, short shouldDelete);

void operator delete(void*);

extern "C" void* fn_92_4154(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_1F64(storage + 0x14, 0);
        fn_92_1FC0(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
