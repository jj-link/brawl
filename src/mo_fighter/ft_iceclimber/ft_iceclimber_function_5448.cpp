#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_4C94(void*, short);
extern "C" void* fn_105_54B4(void*, short);

extern "C" void* fn_105_5448(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_105_4C94(static_cast<char*>(object) + 0x47B8, minus_one);
        fn_105_54B4(static_cast<char*>(object) + 0x4, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
