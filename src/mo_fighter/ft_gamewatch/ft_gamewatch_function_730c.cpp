#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_107_7384(void* object, short deleteFlag);

extern "C" void* fn_107_730C(void* object, short deleteFlag) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_1A1B88(p + 0xF0, -1);
        if (object != 0) {
            fn_107_7384(object, 0);
        }
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
