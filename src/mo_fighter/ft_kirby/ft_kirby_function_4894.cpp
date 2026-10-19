#pragma force_active on
void operator delete(void*);
extern "C" void fn_96_47E4(void*, short);
extern "C" void fn_96_4778(void*, short);

extern "C" void* fn_96_4894(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_47E4(storage + 0x24, -1);
        fn_96_4778(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
