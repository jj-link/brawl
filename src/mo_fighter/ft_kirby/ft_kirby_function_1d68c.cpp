#pragma force_active on
#pragma opt_propagation off
#include <revolution/OS/OSError.h>

extern "C" {
extern char lbl_96_data_BBCC[];
int fn_27_C37B4(void*);
unsigned char* fn_96_1D7B4(int);
unsigned char* fn_96_1C78C(void*, int);
void* fn_27_C36B0(void*, int, void*);
void fn_27_1E83A4(void*);
void fn_27_C35F0(void*, int);

void fn_96_1D68C(unsigned char* self, int ability) {
    if (fn_27_C37B4(self + 0xC) != 0) {
        OSReport(lbl_96_data_BBCC, ability);
        unsigned char* table = fn_96_1D7B4(ability);
        for (int i = 0; i < *reinterpret_cast<int*>(table + 4); ++i) {
            unsigned char* record = fn_96_1C78C(table, i);
            void* object = *reinterpret_cast<void**>(record + 8);
            fn_27_1E83A4(fn_27_C36B0(self + 0xC, ability, object));
        }
        fn_27_C35F0(self + 0xC, ability);
    }
}
}
