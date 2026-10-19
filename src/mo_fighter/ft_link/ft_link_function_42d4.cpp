#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_4224(void*, short);
extern "C" void fn_93_41B8(void*, short);

extern "C" void* fn_93_42D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_4224(storage + 0x24, -1);
        fn_93_41B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
