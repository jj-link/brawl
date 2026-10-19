#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_78A8(void*, short);
extern "C" void fn_121_773C(void*, short);

extern "C" void* fn_121_77A8(void* object, short deleting) {
    if (object != 0) {
        fn_121_78A8(static_cast<char*>(object) + 0x3FC8, -1);
        fn_121_773C(static_cast<char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
