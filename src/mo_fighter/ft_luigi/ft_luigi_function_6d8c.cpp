#pragma force_active on
extern "C" {
void fn_27_199DDC(void*, int, int);
void fn_27_6A244(void*, void*, void*);
}

extern "C" void* fn_99_6D8C(void* object, void* owner) {
    fn_27_199DDC(object, 6, 0);
    fn_27_6A244((unsigned char*)object + 0x144, owner, object);
    return object;
}
