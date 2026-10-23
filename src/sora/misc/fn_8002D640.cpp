#pragma force_active on

struct gfSceneManager {
    char pad0[0x14];
    void* unk14;
    char pad18[0x190];
    void* unk1A8[0x33];
    int unk274;
    char pad278[0x14];
    int unk28C;
    char pad290[0x8C];
    int unk31C;
};

extern "C" int strcmp(const char*, const char*);

extern "C" void setNextSequence__14gfSceneManagerFv(
    gfSceneManager* self, const char* name, int arg)
{
    int i;
    char* p = (char*)self;
    int n = self->unk274;
    void* res;

    for (i = 0; i < n; i++) {
        if (strcmp(**(const char***)(p + 0x1A8), name) == 0) {
            res = self->unk1A8[i];
            goto done;
        }
        p += 4;
    }
    res = 0;

done:
    self->unk14 = res;
    self->unk31C = arg;
    self->unk28C = 3;
}
