#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_4C94(void*, short);
extern "C" void* fn_105_5520(void*, short);

extern "C" void* fn_105_54B4(void* object, short deleting) {
    if (object != 0) {
        fn_105_4C94(static_cast<char*>(object) + 0x23e0, -1);
        fn_105_5520(static_cast<char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
