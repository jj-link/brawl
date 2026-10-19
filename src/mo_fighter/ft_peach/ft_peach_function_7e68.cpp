#include <types.h>
#pragma force_active on

extern "C" {

void fn_27_198524(void* obj, int param1, int param2);
void fn_27_68888(void* a, void* b, void* c, void* d);

void* fn_103_7E68(void* obj, void* arg1, void* arg2) {
    fn_27_198524(obj, 4, 0);
    fn_27_68888(static_cast<char*>(obj) + 0x7c, arg1, obj, arg2);
    return obj;
}

}
