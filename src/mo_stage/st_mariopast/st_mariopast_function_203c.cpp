#pragma force_active on
extern "C" unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" unsigned int fn_48_203C(const void* self) {
    const char* base = (const char*)self;
    if (*(const void**)(base + 0x40) != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(base + 0x40);
    return 0;
}
