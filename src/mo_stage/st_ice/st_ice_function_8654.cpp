#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void* fn_62_2CE8(void*, int);
void __dl__FPv(void*);

void* fn_62_8654(void* self, int flags)
{
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x180, -1);
        fn_62_2CE8(self, 0);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
}
