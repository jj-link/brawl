#pragma force_active on

struct MuObject {
    char pad[0x14];
    void* animation;
};

struct Entry {
    char name[0x41];
    unsigned char first;
    unsigned char last;
    unsigned char argument;
};

struct ObjectList {
    char pad[0x104];
    MuObject* objects[1];
};

struct Menu {
    char pad[0x1ac];
    ObjectList* list;
};

extern "C" {
extern char lbl_6_data_130[];
extern const float lbl_6_rodata_1C4;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_6_1BCC(Menu* self, Entry* entries, int count, void* resourceFile) {
    int num;
    int i = 0;
    int j;
    Entry* entry = entries;
    MuObject* object;
    char animationName[0x40];

    while (i < count) {
        num = 1;
        if (entry->first < entry->last)
            num = entry->last - entry->first;

        j = 0;
        while (j < num) {
            object = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resourceFile, entry->name, entry->argument, 0, 42);
            self->list->objects[entry->first + j] = object;
            strcpy(animationName, entry->name);
            strcat(animationName, lbl_6_data_130);
            changeAnimN__8MuObjectFPCc(object, animationName);
            if (object->animation)
                setUpdateRate__16gfModelAnimationFf(
                    object->animation, lbl_6_rodata_1C4);
            ++j;
        }
        ++i;
        ++entry;
    }
}
