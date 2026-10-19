#pragma force_active on
typedef unsigned char u8;

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

struct Owner {
    char pad[0x44];
    void* objs[1];
};

extern "C" {
extern char lbl_2_data_4BE4[];
extern const float lbl_2_rodata_1750;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_2_38950(void* self, Entry* entries, int count, void* resFile, int flag, int offset) {
    char buf[72];
    int n;
    int i;
    int j;
    void* obj;
    Entry* entry = entries;

    for (i = 0; i < count; i++, entry++) {
        n = 1;
        if (entry->begin < entry->end) {
            n = entry->end - entry->begin;
        }
        for (j = 0; j < n; j++) {
            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, entry->name, entry->kind + offset, 0, 0x2a);
            const char* name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            if (flag != 0) {
                strcat(buf, lbl_2_data_4BE4);
            }
            changeAnimN__8MuObjectFPCc(obj, buf);
            if (*(void**)((char*)obj + 0x14) != 0) {
                setUpdateRate__16gfModelAnimationFf(*(void**)((char*)obj + 0x14), lbl_2_rodata_1750);
            }
        }
    }
}
