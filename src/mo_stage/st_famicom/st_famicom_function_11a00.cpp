#pragma force_active on
extern "C" void __dl__FPv(void* ptr);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void* fn_68_23FC(void* self, int flag);
extern "C" unsigned char lbl_68_data_3030[];

extern "C" void* fn_68_11A00(void* self, int flags) {
    if (self != 0) {
        void** object = (void**)self;
        object[0x3C / 4] = lbl_68_data_3030;

        if (object[0x17C / 4] != 0) {
            __dl__FPv(object[0x17C / 4]);
        }

        object[0x17C / 4] = 0;
        __dt__14snd3DGeneratorFv((char*)self + 0x180, -1);
        fn_68_23FC(self, 0);

        if (flags > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
