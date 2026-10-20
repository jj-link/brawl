#pragma force_active on
extern "C" void fn_27_58198(void* obj, void* a, void* b, void* c);

extern "C" void fn_27_56BC4(void* self, void* a, void* b) {
    fn_27_58198(*(void**)((char*)self + 0x3C), b, a, *(void**)((char*)self + 0x34));
}
