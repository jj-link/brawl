#include <types.h>
#pragma force_active on

extern char lbl_27_data_82F70[];
extern char lbl_27_bss_54EC[];

extern "C" {
void fn_27_1E847C(void* self, int size, void* data);
void __dl__FPv(void* p);

struct stSoraObj;
void* fn_27_30B9F0(stSoraObj* self, int flag);
}

struct stSoraObj {
    char* m0;
    int m4;
    char* m8;
};

extern "C" void* fn_27_30B9F0(stSoraObj* self, int flag) {
    if (self) {
        self->m8 = lbl_27_data_82F70;
        self->m0 = lbl_27_data_82F70 + 8;
        fn_27_1E847C(self, 0x3c, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
