#pragma force_active on

struct MuObject {
    char pad[0x14];
    void* animation;
};

struct MenuEntry {
    const char* name;
    unsigned char first, last, argument, pad;
};

struct ObjectTable {
    char pad[0x10];
    MuObject* objects[1];
};

struct Menu {
    char pad[0x40];
    ObjectTable* table;
};

extern "C" {
extern char lbl_2_data_3F88[];
extern float lbl_2_rodata_13FC;
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_2_3157C(Menu* self, MenuEntry* entries, int count, void* resourceFile) {
    int num;
    int i = 0;
    int j;
    MenuEntry* entry = entries;
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
            self->table->objects[entry->first + j] = object;
            strcpy(animationName, name);
            strcat(animationName, lbl_2_data_3F88);
            changeAnimN__8MuObjectFPCc(object, animationName);
            if (object->animation)
                setUpdateRate__16gfModelAnimationFf(object->animation, lbl_2_rodata_13FC);
            ++j;
        }
        ++i;
        ++entry;
    }
}
