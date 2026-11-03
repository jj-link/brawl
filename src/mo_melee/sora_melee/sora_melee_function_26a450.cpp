#pragma force_active on

class Obj {
public:
    virtual void method(int);
};

extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_803F0D4C(void*, void (*)(void*, int));
void fn_27_262230(void*, int);
void fn_27_25F4B0(void*, int);
extern char lbl_27_data_568E8[];

void* __dt__9grGimmickFv(void* self, int flag) {
    if (self != 0) {
        char* base = (char*)self;

        void* ptr_a0 = *(void**)(base + 0xA0);
        *(void**)(base + 0x3C) = lbl_27_data_568E8;

        if (ptr_a0 != 0) {
            fn_803F0D4C(ptr_a0, __dt__14snd3DGeneratorFv);
            *(void**)(base + 0xA0) = 0;
        }

        void* ptr_a8 = *(void**)(base + 0xA8);
        if (ptr_a8 != 0) {
            if (ptr_a8 != 0) {
                __dla__FPv((char*)ptr_a8 - 0x10);
            }
            *(void**)(base + 0xA8) = 0;
        }

        void* ptr_b0 = *(void**)(base + 0xB0);
        if (ptr_b0 != 0) {
            if (ptr_b0 != 0) {
                __dla__FPv((char*)ptr_b0 - 0x10);
            }
            *(void**)(base + 0xB0) = 0;
        }

        char* cursor = base;
        for (int i = 0; i < 10; ++i, cursor += 4) {
            Obj* entry = *(Obj**)(cursor + 0xFC);
            if (entry != 0) {
                if (entry != 0) {
                    entry->method(1);
                }
                *(void**)(cursor + 0xFC) = 0;
            }

            Obj* entry2 = *(Obj**)(cursor + 0x124);
            if (entry2 != 0) {
                if (entry2 != 0) {
                    entry2->method(1);
                }
                *(void**)(cursor + 0x124) = 0;
            }
        }

        if (*(void**)(base + 0xB8) != 0) {
            __dl__FPv(*(void**)(base + 0xB8));
        }

        fn_27_262230(base + 0xD0, -1);
        fn_27_25F4B0(self, 0);

        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}