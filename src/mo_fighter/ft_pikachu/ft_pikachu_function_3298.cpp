#pragma force_active on
extern "C" void* fn_98_32F4(char*, short);

extern "C" void* fn_98_3298(char* obj, short deleting) {
    if (obj) {
        fn_98_32F4(obj, short(0));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
