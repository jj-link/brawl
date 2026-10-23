#pragma force_active on

struct Holder {
    char pad[0xd4];
    int* inner;
};

extern "C" void* __memcpy(void*, const void*, unsigned long);
extern "C" void fn_8003E5B4(int*);
extern "C" void fn_27_26DB64(Holder*, const void*);

extern "C" void fn_27_279FC8(Holder* self, int* src, int arg) {
    int* d = self->inner + 20;
    __memcpy(d, src, 0x30);
    if (arg == 0) {
        fn_8003E5B4((int*)((char*)self->inner + 0x50));
    }
    fn_27_26DB64(self, src);
}
