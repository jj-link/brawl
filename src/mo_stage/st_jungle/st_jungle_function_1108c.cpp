#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void* fn_51_3C30(void*, int);
void operator delete(void*);

extern "C" void* fn_51_1108C(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1A8, -1);
        fn_51_3C30(self, 0);
        if (flags > 0)
            operator delete(self);
    }
    return self;
}
