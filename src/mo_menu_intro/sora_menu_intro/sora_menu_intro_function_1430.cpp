#include <types.h>
#pragma force_active on

struct SceneEntry {
    const char* name;
    u8 begin;
    u8 end;
    u8 index;
    u8 pad;
};

extern "C" {
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void* resFile, const char* name, int index, void* subFile, int heapType);
void changeAnimN__8MuObjectFPCc(void* obj, const char* name);
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);
char* strcpy(char* dst, const char* src);
char* strcat(char* dst, const char* src);
extern char lbl_13_data_148[];
extern float lbl_13_rodata_4C;
}

extern "C" void fn_13_1430(void* self, SceneEntry* entries, int count, void* resFile) {
    char buf[0x40];
    int n;
    int i;
    int j;
    SceneEntry* p = entries;
    for (i = 0; i < count; i++, p++) {
        n = 1;
        if (p->begin < p->end) {
            n = p->end - p->begin;
        }
        for (j = 0; j < n; j++) {
            void* obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(resFile, p->name, p->index, 0, 0x2a);
            const char* name = p->name;
            *(void**)((u8*)self + ((p->begin + j) << 2) + 0x60) = obj;
            strcpy(buf, name);
            strcat(buf, lbl_13_data_148);
            changeAnimN__8MuObjectFPCc(obj, buf);
            void* anim = *(void**)((u8*)obj + 0x14);
            if (anim != 0) {
                setUpdateRate__16gfModelAnimationFf(anim, lbl_13_rodata_4C);
            }
        }
    }
}
