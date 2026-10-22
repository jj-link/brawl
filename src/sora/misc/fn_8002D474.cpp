#pragma force_active on

extern "C" int strcmp(const char*, const char*);

struct SeqEntry {
    const char* name;
};

struct gfSceneManager {
    char pad0[0x1A8];
    SeqEntry* list[0x33];
    int count;
};

extern "C" SeqEntry* searchSequence__14gfSceneManagerFv(
    gfSceneManager* self, const char* name)
{
    int count = self->count;
    for (int i = 0; i < count; ++i) {
        if (strcmp(self->list[i]->name, name) == 0) {
            return self->list[i];
        }
    }
    return 0;
}
