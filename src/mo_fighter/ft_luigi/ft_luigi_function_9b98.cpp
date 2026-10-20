#include <types.h>
#pragma force_active on

extern "C" void* fn_99_9CCC(void*, int);
extern "C" void* fn_99_9CB4(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_99_9B98(void* object) {
    int i = 0;

    for (; i < 2; ++i) {
        if (fn_27_8D3E4(
                static_cast<char*>(fn_99_9CCC(
                    static_cast<char*>(object) + 0x20A8, i)) + 0x88) == 0)
            goto done;
    }

    for (i = 0; i < 1; ++i) {
        if (fn_27_8D3E4(
                static_cast<char*>(fn_99_9CB4(
                    static_cast<char*>(object) + 0xC, i)) + 0x88) == 0)
            goto done;
    }

done:
    return;
}
