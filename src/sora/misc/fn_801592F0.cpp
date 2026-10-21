#pragma force_active on
extern "C" void* fn_8015B17C(void*, int);

struct UnkObj {
    void* unk0;
    void* unk4;
    void* unk8;
};

extern "C" void fn_801592F0(UnkObj* p) {
    if (p->unk8) {
        fn_8015B17C(p->unk8, 1);
    }
    p->unk8 = 0;
}
