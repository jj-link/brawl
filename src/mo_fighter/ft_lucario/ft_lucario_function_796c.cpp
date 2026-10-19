#pragma force_active on
extern "C" void fn_27_1999C4(void*, int, int);
extern "C" void fn_27_19BF3C(void*, int, int);
extern "C" void fn_27_150320(void*, void*, short, void*, void*);

extern "C" void* fn_118_796C(void* object, void* arg2, short arg3) {
    fn_27_1999C4(object, 10, 0);
    fn_27_19BF3C(static_cast<unsigned char*>(object) + 0x584, 2, 0);
    fn_27_150320(static_cast<unsigned char*>(object) + 0x5B8, arg2, arg3, object, (char*)object + 0x584);
    return object;
}
