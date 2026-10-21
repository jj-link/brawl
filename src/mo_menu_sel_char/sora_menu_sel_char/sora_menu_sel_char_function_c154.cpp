#pragma force_active on

struct MuObject {
    char pad[0x14];
    void* animation;
};

struct Entry {
    const char* name;
    unsigned char first, last, argument, pad;
};

struct Menu {
    char pad[0x13C];
    MuObject* objects[1];
};

extern "C" {
extern char lbl_10_data_558[];
extern const float lbl_10_rodata_2F0;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_10_C154(Menu* self, Entry* entries, int count,
                           void* resourceFile, void* otherResource, int flag) {
    int num;
    int i = 0;
    int j;
    Entry* entry = entries;
    MuObject* object;
    const char* name;
    char animationName[0x40];

    while (i < count) {
        num = 1;
        if (entry->first < entry->last)
            num = entry->last - entry->first;

        j = 0;
        while (j < num) {
            object = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resourceFile, entry->name,
                flag ? entry->argument + j : entry->argument,
                otherResource, 0x2A);
            name = entry->name;
            self->objects[entry->first + j] = object;
            strcpy(animationName, name);
            strcat(animationName, lbl_10_data_558);
            changeAnimN__8MuObjectFPCc(object, animationName);
            if (object->animation)
                setUpdateRate__16gfModelAnimationFf(object->animation, lbl_10_rodata_2F0);
            ++j;
        }
        ++i;
        ++entry;
    }
}
