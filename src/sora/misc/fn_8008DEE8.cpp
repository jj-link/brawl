#pragma force_active on

struct Entry {
    char pad0[0x90];
    char name[0x110];
    int id;
    char pad1[0x5C];
    int disabled;
};

struct List {
    Entry** entries;
    int count;
    char pad[5];
    unsigned char flag;
};

struct Node {
    char pad[0xC];
    int id;
};

extern "C" Node* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);

extern "C" int fn_8008DEE8(List* self, int* output, void* model) {
    int* out;
    int count = 0;

    if (self->flag) {
        int* direct = output;
        for (int i = self->count - 1; i >= 0; --i) {
            Entry* entry = self->entries[i];
            if (entry->disabled == 0) {
                ++count;
                *direct++ = entry->id;
            }
        }
    } else {
        out = output;
        for (int i = self->count - 1; i >= 0; --i) {
            Entry* entry = self->entries[i];
            if (entry->disabled == 0) {
                Node* node =
                    GetResNode__Q34nw4r3g3d6ResMdlCFPCc(model, entry->name);
                *out++ = node ? node->id : 0;
                ++count;
            }
        }
    }

    return count;
}
