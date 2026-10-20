#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_48BE8(void*, short);
extern "C" void fn_27_4742C(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CDDE8(void*, short);
extern "C" void fn_27_CD78C(void*, short);

extern "C" void* fn_97_7814(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        short minus_one = -1;
        fn_27_48BE8(storage + 0x1C4, minus_one);
        fn_27_4742C(storage + 0x1B4, minus_one);
        fn_27_4CAA0(storage + 0x130, minus_one);
        fn_27_CDDE8(storage + 0x6C, minus_one);
        fn_27_CD78C(self, minus_one);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
