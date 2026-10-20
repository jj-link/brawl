#include <cstring>
#pragma force_active on

extern "C" {
extern char lbl_16_data_3560[];
extern float lbl_16_rodata_180;
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
}

struct AnimEntry {
    const char* name;
    unsigned char first;
    unsigned char last;
    unsigned char idOffset;
    unsigned char pad;
};

extern "C" void fn_16_25A0(void* self, AnimEntry* entries, int entryCount, void* resFile, int useSuffix, int idBase) {
    char buf[0x40];
    int n;
    int i;
    int j;
    AnimEntry* e;
    for (i = 0, e = entries; i < entryCount; i++, e++) {
        n = 1;
        if (e->first < e->last) {
            n = e->last - e->first;
        }
        for (j = 0; j < n; j++) {
            void* obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, e->name, e->idOffset + idBase, 0, 0x2a);
            const char* name = e->name;
            ((void**)self)[16 + e->first + j] = obj;
            strcpy(buf, name);
            if (useSuffix) {
                strcat(buf, lbl_16_data_3560);
            }
            changeAnimN__8MuObjectFPCc(obj, buf);
            void* anim = *(void**)((char*)obj + 0x14);
            if (anim != 0) {
                setUpdateRate__16gfModelAnimationFf(anim, lbl_16_rodata_180);
            }
        }
    }
}
