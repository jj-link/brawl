#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_1F18(void*, short);
extern "C" void* fn_96_1F74(void*, short);

extern "C" void* fn_96_4778(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_1F18(storage + 0x14, 0);
        fn_96_1F74(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
