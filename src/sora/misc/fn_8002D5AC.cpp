#pragma force_active on
struct gfSceneManager {
    char pad0[8];
    void* unk8;
    char padC[0xC];
    void* unk18[0x96];
    int unk270;
    char pad274[0xC];
    int unk280;
    int pad284;
    int unk288;
};

extern "C" int strcmp(const char*, const char*);

extern "C" void setNextScene__14gfSceneManagerFv(gfSceneManager* self, const char* name, int arg) {
    int i;
    char* p = (char*)self;
    int n = self->unk270;
    void* res;
    for (i = 0; i < n; i++) {
        if (strcmp(**(const char***)(p + 0x18), name) == 0) {
            res = self->unk18[i];
            goto done;
        }
        p += 4;
    }
    res = 0;
done:
    self->unk8 = res;
    self->unk280 = arg;
    self->unk288 = 3;
}
