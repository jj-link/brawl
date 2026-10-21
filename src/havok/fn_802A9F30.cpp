#pragma force_active on
struct Obj {
    virtual void v2(int);
    char pad[4];
    int unk8;
    int unkC;
};

extern "C" void fn_802FC6AC(void*, int, int);

extern "C" void fn_802A9F30(Obj* arg0) {
    fn_802FC6AC((char*)arg0 + 0x30, arg0->unkC, arg0->unk8);
    if (arg0 != (Obj*)0) {
        arg0->v2(1);
    }
}
