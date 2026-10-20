#pragma force_active on
typedef unsigned char u8;

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

struct Owner {
    char pad[0x40];
    void* objs[1];
};

extern "C" {
extern char lbl_12_data_20[];
extern const float lbl_12_rodata_40;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_12_25C(void* self, Entry* entries, int count, void* resFile) {
    int n;
    int i = 0;
    int j;
    Entry* entry = entries;
    void* obj;
    const char* name;
    char buf[64];

    for (i = 0; i < count; i++, entry++) {
        n = 1;
        if (entry->begin < entry->end) {
            n = entry->end - entry->begin;
        }
        for (j = 0; j < n; j++) {
            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, entry->name, entry->kind, 0, 0x2a);
            name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_12_data_20);
            changeAnimN__8MuObjectFPCc(obj, buf);
            if (*(void**)((char*)obj + 0x14) != 0) {
                setUpdateRate__16gfModelAnimationFf(
                    *(void**)((char*)obj + 0x14), lbl_12_rodata_40);
            }
        }
    }
}
