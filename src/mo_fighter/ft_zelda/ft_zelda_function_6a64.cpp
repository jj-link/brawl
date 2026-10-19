#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_104_6AD0(void* p, short flags);
void operator delete(void*);

extern "C" void* fn_104_6A64(void* p, short deleting) {
    if (p != 0) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0x14, -1);
        fn_104_6AD0(p, -1);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
