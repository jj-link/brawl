#pragma force_active on
extern "C" void fn_80204E6C(int a, int b);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_804659B0[];
extern "C" int lbl_805A0508;

struct Obj {
    void* unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
    int unk14;
    int unk18;
    short unk1C;
};

extern "C" void* fn_8018B3F4(void* arg0, int arg1) {
    if (arg0) {
        Obj* p = (Obj*)arg0;
        int v = p->unk18;
        p->unk0 = lbl_804659B0;
        if (v != 0) {
            fn_80204E6C(lbl_805A0508, v);
        }
        int v2 = p->unk14;
        if (v2 != 0) {
            fn_80204E6C(lbl_805A0508, v2);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
