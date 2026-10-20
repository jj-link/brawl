#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;

struct Entry {
    const char* name;
    u16 begin;
    u16 end;
    u8 kind;
    u8 pad;
};

struct Owner {
    char pad[0x4c];
    void* objs[1];
};

extern "C" {
extern char lbl_15_data_14C[];
extern const float lbl_15_rodata_0;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_15_CA0(void* self, Entry* entries, int count, void* resFile, int kindOffset) {
    char buf[64];
    int n;
    int i;
    int j;
    Entry* entry = entries;
    void* obj;

    for (i = 0; i < count; i++, entry++) {
        n = 1;
        if (entry->begin < entry->end) {
            n = entry->end - entry->begin;
        }
        for (j = 0; j < n; j++) {
            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, entry->name, entry->kind + kindOffset, 0, 0x2a);
            const char* name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_15_data_14C);
            changeAnimN__8MuObjectFPCc(obj, buf);
            if (*(void**)((char*)obj + 0x14) != 0) {
                setUpdateRate__16gfModelAnimationFf(*(void**)((char*)obj + 0x14), lbl_15_rodata_0);
            }
        }
    }
}
