#pragma force_active on
void operator delete(void*);
extern "C" void fn_115_BBF0(void*, short);

extern "C" void* fn_115_BC50(void* object, short deleting) {
    if (object != 0) {
        fn_115_BBF0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
