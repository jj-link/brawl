#pragma force_active on
extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

struct SomeStruct {
    char pad[0x40];
    void* resFile;
};

extern "C" unsigned int fn_49_1900(SomeStruct* self) {
    if (self->resFile != 0) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile);
    }
    return 0;
}
