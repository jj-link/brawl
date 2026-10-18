#pragma force_active on
extern "C" {

typedef unsigned int u32;

extern u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

u32 fn_51_33B4(const void* self) {
    const u32* p = (const u32*)self;
    u32 val = p[16];
    if (val != 0) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&p[16]);
    }
    return 0;
}

}
