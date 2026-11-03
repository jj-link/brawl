#include <types.h>
#pragma force_active on

extern "C" {
void fn_8015BF9C(void*, int);
extern char lbl_80465258[];
}

extern "C" void* fn_801639DC(void* arg0) {
    char* p = (char*)arg0;
    *(void**)(p + 0x1C) = lbl_80465258;
    {
        void fn_8015BF9C(void*, int, void*);
        fn_8015BF9C(p + 0x24, 0x14, lbl_80465258);
    }
    fn_8015BF9C(p + 0x30, 0x14);
    *(short*)(p + 0x3C) = 0;
    fn_8015BF9C(p + 0x90, 0x30);
    return arg0;
}
