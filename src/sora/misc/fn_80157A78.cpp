#include <types.h>
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern "C" {
void* fn_80037DD0(void*);
void* fn_80037E64(void*, int);
int fn_80037F74(void*, unsigned int, unsigned int, int);
void fn_80157E8C(void*, int, int);
void fn_80157FD4(void*, int, int);
}

struct Work {
    char pad[0x370];
    unsigned char done;
    char pad1[3];
    int result;
    int a;
    int b;
    unsigned char flag;
    char pad2[3];
};

extern "C" void fn_80157A78(unsigned char* self, int event, int status, unsigned int size) {
    switch (event) {
    case 1:
        if (status != 0)
            self[0x37c] = 1;
        break;
    case 3:
        if (status == 0) {
            Work work;
            fn_80037DD0(&work);
            work.flag = 1;
            if (fn_80037F74(&work, *(unsigned int*)(self + 0x358), size, *(int*)(self + 0x350))) {
                while (!work.done)
                    OSSleepTicks((*(unsigned int*)0x800000F8 / 4) / 1000);
                if (work.result == 0) {
                    if (*(int*)(self + 0x354) == 1)
                        fn_80157E8C(self, work.a, work.b);
                    else if (*(int*)(self + 0x354) == 2)
                        fn_80157FD4(self, work.a, work.b);
                }
            }
            fn_80037E64(&work, -1);
        }
        if (*(void**)(self + 0x358)) {
            gfHeapManager::free(*(void**)(self + 0x358));
            *(void**)(self + 0x358) = 0;
        }
        self[0x35c] = 1;
        break;
    }
}