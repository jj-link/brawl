#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void fn_94_5D70(void*, short);
void* fn_27_199A54(void*, short);

void* fn_94_5CF0(void* object, short deleting) {
    if (object != 0) {
        fn_27_150488(static_cast<unsigned char*>(object) + 0x5B8, -1);
        fn_94_5D70(static_cast<unsigned char*>(object) + 0x584, -1);
        if (object != 0) {
            fn_27_199A54(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
