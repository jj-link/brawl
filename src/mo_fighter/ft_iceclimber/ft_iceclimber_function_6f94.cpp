#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_7000(void*, short);
extern "C" void* fn_105_4228(void*, short);

extern "C" void* fn_105_6F94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_7000(storage + 0x24, -1);
        fn_105_4228(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
