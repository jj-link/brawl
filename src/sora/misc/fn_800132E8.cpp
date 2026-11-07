#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" void fn_800132E8(void* arg0) {
    unsigned int j;
    void* temp_r29;
    unsigned int k;
    void* temp_r27;
    char* p1;
    char* c1;
    char* c2;
    void* temp_r23;
    unsigned int i;

    char* o = (char*)arg0;
    if (!(((unsigned char)o[0x11] >> 7) & 1)) {
        temp_r23 = *(void**)(o + 0x18);
        p1 = o;
        i = 0;
        do {
            c1 = (char*)*(void**)(p1 + 0x18);
            if (!(((unsigned char)c1[0x11] >> 7) & 1)) {
                temp_r29 = *(void**)(c1 + 0x18);
                j = 0;
                do {
                    c2 = (char*)*(void**)(c1 + 0x18);
                    if (!(((unsigned char)c2[0x11] >> 7) & 1)) {
                        temp_r27 = *(void**)(c2 + 0x18);
                        k = 0;
                        do {
                            fn_800132E8(*(void**)(c2 + 0x18));
                            k++;
                            *(void**)(c2 + 0x18) = NULL;
                            c2 += 4;
                        } while (k < 4);
                        gfHeapManager::free(temp_r27);
                    }
                    j++;
                    *(void**)(c1 + 0x18) = NULL;
                    c1 += 4;
                } while (j < 4);
                gfHeapManager::free(temp_r29);
            }
            i++;
            *(void**)(p1 + 0x18) = NULL;
            p1 += 4;
        } while (i < 4);
        gfHeapManager::free(temp_r23);
    }
}
