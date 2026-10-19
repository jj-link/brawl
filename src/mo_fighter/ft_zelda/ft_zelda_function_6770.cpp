#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_67DC(void*, short);
extern "C" void* fn_104_425C(void*, short);

extern "C" void* fn_104_6770(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_67DC(storage + 0x24, -1);
        fn_104_425C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
