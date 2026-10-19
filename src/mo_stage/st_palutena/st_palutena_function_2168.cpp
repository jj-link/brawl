#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[0x40];
    void* pPtr;
} ResFileHolder;

extern "C" u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void* resFile);

extern "C" u32 fn_67_2168(ResFileHolder* holder) {
    if (holder->pPtr != 0)
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&holder->pPtr);
    return 0;
}
