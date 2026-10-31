#include <types.h>
#pragma force_active on

extern "C" void fn_802F064C(void* p);

extern "C" void fn_802DE8BC(u32* arg0) {
    u32* cur = arg0;
    int i = 0;

    while (i < 2) {
        int val = cur[5];
        if (val == 0) {
            int t = val ^ arg0[5];
            int target = arg0[6] ^ t;
            if (target != 0) {
                int ptr = *(int*)(target + 8);
                if (ptr != 0) {
                    int result = *(int*)(ptr + 0x24);
                    cur[5] = result;
                    fn_802F064C((void*)result);
                }
            }
        }
        i++;
        cur++;
    }
}
