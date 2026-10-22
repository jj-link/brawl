#pragma force_active on

typedef unsigned char u8;

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

struct Owner {
    void* field0;
    void* objs[1];
};

extern "C" {
extern char lbl_8059E528[4];
extern const float lbl_805A2748;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_800FEB64(
    void* self, Entry* entries, int count, void* resFile, int priority)
{
    char buf[0x40];
    int n;
    int i;
    int j;
    Entry* entry = entries;
    void* obj;

    for (i = 0; i < count; i++, entry++) {
        n = 1;
        if (entry->begin < entry->end)
            n = entry->end - entry->begin;

        for (j = 0; j < n; j++) {
            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, entry->name, entry->kind + (j + priority), 0, 0x28);

            const char* name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_8059E528);
            changeAnimN__8MuObjectFPCc(obj, buf);

            if (*(void**)((char*)obj + 0x14) != 0)
                setUpdateRate__16gfModelAnimationFf(
                    *(void**)((char*)obj + 0x14), lbl_805A2748);
        }
    }
}
