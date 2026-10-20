#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_1BEA4(void*, short);
extern "C" void* fn_105_5220(void*, short);
extern "C" void* fn_105_5290(void*, short);

extern "C" void* fn_105_1A810(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_1BEA4(storage + 0xE0, -1);
        fn_105_5220(storage + 0x30, -1);
        fn_105_5290(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
