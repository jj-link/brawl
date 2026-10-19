#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dt__15grGimmickSpringFv(void* self, int flags);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_63_16454(void* self, int flags)
{
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1C0, -1);
        __dt__15grGimmickSpringFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
