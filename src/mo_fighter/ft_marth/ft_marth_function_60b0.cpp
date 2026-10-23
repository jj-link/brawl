#pragma force_active on
extern "C" void fn_27_199F1C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_106_60B0(void* object, void* arg) {
    fn_27_199F1C(object, 7, 0);
    fn_27_6A244((char*)object + 0x178, arg, object);
    return object;
}
