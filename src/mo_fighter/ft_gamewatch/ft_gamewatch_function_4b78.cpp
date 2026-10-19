#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_3548(void*, short);
extern "C" void* fn_107_4BE4(void*, short);

extern "C" void* fn_107_4B78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_3548(storage + 0x21b8, -1);
        fn_107_4BE4(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
