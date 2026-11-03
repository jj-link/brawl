#include <types.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" int fn_8005EC64(void* self, void* arg);

extern "C" int fn_80014348(void* self, unsigned int index, int* result) {
    char* ptr;
    char* rp;
    char* target;
    int w;
    char* node = *(char**)((char*)self + 0x68);
    while (node) {
        unsigned int count = *(unsigned short*)(node + 2);
        ptr = node + 8;
        for (unsigned int i = 0; i < count; i++) {
            w = *(int*)ptr;
            if ((w >> 24) == 8) {
                rp = *(char**)(ptr + 8);
                if (rp) {
                    if (index == 0) {
                        if (*(unsigned short*)(rp + 4) == 0x101) {
                            target = rp + 0x10;
                        } else {
                            target = 0;
                        }
                        if (target) {
                            *result = fn_8005EC64(g_ecMgr, target);
                        } else {
                            *result = 0x137;
                        }
                        return 1;
                    }
                    index--;
                }
            }
            ptr += 0x10;
        }
        node = *(char**)(node + 4);
    }
    return 0;
}