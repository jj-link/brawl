#pragma force_active on

typedef unsigned char u8;

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

struct Owner {
    char pad[4];
    void* objs[1];
};

extern "C" {
extern char lbl_8059E5C0[4];
extern const float lbl_805A27B8;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_80104B6C(
    void* self, Entry* entries, int count, void* resFile, int prio)
{
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
                resFile, entry->name, entry->kind + (j + prio), 0, 0x28);

            const char* name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_8059E5C0);
            changeAnimN__8MuObjectFPCc(obj, buf);

            if (*(void**)((char*)obj + 0x14) != 0) {
                setUpdateRate__16gfModelAnimationFf(
                    *(void**)((char*)obj + 0x14), lbl_805A27B8);
            }
        }
    }
}
