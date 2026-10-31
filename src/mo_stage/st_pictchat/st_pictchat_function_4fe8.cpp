#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_263738(void* self);

extern "C" void fn_73_4FE8(char* self) {
    void* p = *(void**)(self + 0x14c);
    if (p == 0) {
        return;
    }
    fn_27_263738(p);
}
