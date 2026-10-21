#pragma force_active on

typedef unsigned char u8;

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
    u8 useResource : 1;
    u8 incrementKind : 1;
    u8 unused : 6;
};

struct Owner {
    char pad[0x54];
    void* objs[1];
};

extern "C" {
extern char lbl_11_data_288[];

void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}

extern "C" void fn_11_118C(
    void* self, Entry* entries, int count, void* resFile,
    void* otherResFile, int argument)
{
    char buf[0x48];
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
            void* resource = entry->useResource ? otherResFile : 0;
            int kind = entry->kind + argument;
            if (entry->incrementKind)
                kind += j;

            obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                resFile, entry->name, kind, resource, 0x2a);

            const char* name = entry->name;
            ((Owner*)self)->objs[entry->begin + j] = obj;
            strcpy(buf, name);
            strcat(buf, lbl_11_data_288);
            changeAnimN__8MuObjectFPCc(obj, buf);
        }
    }
}
