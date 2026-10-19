#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_4F74(void*, short);
extern "C" void* fn_107_1C848(void*, short);

extern "C" void* fn_107_1C7D8(void* object, short deleting) {
    if (object != 0) {
        fn_107_4F74(static_cast<unsigned char*>(object) + 0x1990, -1);
        fn_107_1C848(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
