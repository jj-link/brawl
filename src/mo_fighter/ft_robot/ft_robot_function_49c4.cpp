#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_1F24(void*, short);
extern "C" void* fn_120_1F80(void*, short);

extern "C" void* fn_120_49C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short zero = 0;
        fn_120_1F24(storage + 0x14, zero);
        fn_120_1F80(storage + 0x8, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
