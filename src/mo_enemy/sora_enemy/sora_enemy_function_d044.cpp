#pragma force_active on
struct FnCD80Ret {
    unsigned char unk0;
    unsigned char pad[7];
    unsigned int unk8;
};

extern "C" FnCD80Ret* fn_41_CD80(void* mgr, unsigned int id);

extern "C" unsigned int fn_41_D044(void* mgr, unsigned int id) {
    if (id == 0xFFFF) {
        return 0xFFFF;
    }
    FnCD80Ret* p = fn_41_CD80(mgr, id);
    if (p == 0) {
        return 0xFFFF;
    }
    if (p->unk0 == 0) {
        return 0xFFFF;
    }
    return p->unk8;
}
