#pragma force_active on
extern "C" {

unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

struct _st {
    char pad[0x40];
    void* resFile;
};

unsigned int fn_47_1A28(_st* self) {
    if (self->resFile) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    }
    return 0;
}

}
