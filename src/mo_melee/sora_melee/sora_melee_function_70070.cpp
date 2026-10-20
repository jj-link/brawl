#pragma force_active on
enum ARCNodeType { ARCNodeType_0 };
class utArchiveManager {
public:
    void* getResFileFromId(long id, ARCNodeType t, unsigned long a, unsigned long b, unsigned long c);
};
extern void* lbl_27_bss_120[];

struct Ref { unsigned int idx; long id; };

extern "C" void* fn_27_70070(Ref r, ARCNodeType t, unsigned long a, unsigned long b, unsigned long c) {
    return ((utArchiveManager*)lbl_27_bss_120[r.idx])->getResFileFromId(r.id, t, a, b, c);
}
