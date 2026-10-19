#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_94_5F00(void* p, short size);

extern "C" void* fn_94_5E94(void* p, short deleting) {
    if (p != 0) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0x14, -1);
        fn_94_5F00(p, -1);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
