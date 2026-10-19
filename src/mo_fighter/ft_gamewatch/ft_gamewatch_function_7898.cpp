#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_107_7904(void*, short);

extern "C" void* fn_107_7898(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_107_7904(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
