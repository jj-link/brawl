#pragma force_active on

extern "C" int strcmp(const char*, const char*);

struct gfSequence {
    const char* name;
    virtual void start();
};

struct gfSceneManager {
    char pad0[0x10];
    gfSequence* current;
    char pad14[0x194];
    gfSequence* sequences[50];
    char pad270[4];
    int count;
    unsigned char flags : 1;
    unsigned char otherFlags : 7;
    char pad279[0x13];
    int step;
    char pad290[0x8C];
    int arg;
};

extern "C" void changeNextScene__14gfSceneManagerFv(gfSceneManager*);

extern "C" void startSequence__14gfSceneManagerFv(
    gfSceneManager* self, const char* name, int arg
) {
    int i;
    char* p = (char*)self;
    int n = self->count;
    gfSequence* res;

    self->flags = 0;
    for (i = 0; i < n; i++) {
        if (strcmp((*(gfSequence**)(p + 0x1A8))->name, name) == 0) {
            res = self->sequences[i];
            goto done;
        }
        p += 4;
    }
    res = 0;

done:
    self->current = res;
    self->arg = arg;
    res->start();
    self->step = 1;
    changeNextScene__14gfSceneManagerFv(self);
}
