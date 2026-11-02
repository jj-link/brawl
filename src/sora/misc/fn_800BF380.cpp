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
    void* objs[0x33];
    int idx;
};

extern "C" {
extern char lbl_8059E0DC[4];
extern const float lbl_805A22B0;

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
int fn_8018D108(void*, const char*);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_800BF380(
    Owner* self, Entry* entries, int count, void* resFile, int prio, int heap)
{
    char buf[0x40];
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

        self->idx = 0;
        while (self->idx < 1) {
            if (fn_8018D108(resFile, ((const char**)entry)[self->idx]) != 0) break;
            self->idx++;
        }
        const char* name = ((const char**)entry)[self->idx];

        for (j = 0; j < n; j++) {
            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, name, entry->kind + prio, 0, heap);

            self->objs[entry->begin + j - 0 ] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_8059E0DC);
            changeAnimN__8MuObjectFPCc(obj, buf);

            if (*(void**)((char*)obj + 0x14) != 0) {
                setUpdateRate__16gfModelAnimationFf(
                    *(void**)((char*)obj + 0x14), lbl_805A22B0);
            }
        }
    }
}
