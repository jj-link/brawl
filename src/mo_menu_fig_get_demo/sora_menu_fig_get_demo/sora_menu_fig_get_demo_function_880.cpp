#pragma force_active on
struct MuObject { char pad[0x14]; void* animation; };
struct DemoEntry { const char* name; unsigned char first, last, argument, pad; };
struct Menu { char pad[0x6cc]; MuObject* objects[1]; };
extern "C" {
extern char lbl_26_data_24[];
extern float lbl_26_rodata_28;
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}
extern "C" void fn_26_880(Menu* self, DemoEntry* entries, int count, void* resourceFile) {
    int num;
    int i = 0;
    int j;
    DemoEntry* entry = entries;
    MuObject* object;
    const char* name;
    char animationName[0x40];
    while (i < count) {
        num = 1;
        if (entry->first < entry->last)
            num = entry->last - entry->first;
        j = 0;
        while (j < num) {
            object = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(resourceFile, entry->name, entry->argument, 0, 42);
            name = entry->name;
            self->objects[entry->first + j] = object;
            strcpy(animationName, name);
            strcat(animationName, lbl_26_data_24);
            changeAnimN__8MuObjectFPCc(object, animationName);
            if (object->animation)
                setUpdateRate__16gfModelAnimationFf(object->animation, lbl_26_rodata_28);
            ++j;
        }
        ++i;
        ++entry;
    }
}