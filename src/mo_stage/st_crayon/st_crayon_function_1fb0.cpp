#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void* fn_56_1014(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_56_1FB0(void* object, int deleting) {
    if (object != 0) {
        __dt__14snd3DGeneratorFv((char*)object + 0x18C, -1);
        __dt__14snd3DGeneratorFv((char*)object + 0x184, -1);
        fn_56_1014(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
