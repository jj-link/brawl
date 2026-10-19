#pragma force_active on
typedef unsigned int u32;
typedef unsigned long ulong;
typedef unsigned short u16;

extern void* lbl_27_bss_120[];

class utArchiveManager {
public:
    void* getPublicAddress(ulong id, const char* name, u16 flags, ulong a, ulong b);
};

extern "C" void* fn_27_7013C(u32* p, const char* q) {
    return ((utArchiveManager*)lbl_27_bss_120[p[0]])->getPublicAddress(p[1], q, 0, 0, -1);
}
