#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_117_14134(void*, short);

extern "C" void* fn_117_14174(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_117_14134(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
