#pragma force_active on
extern "C" void fn_801EC158(void*);
extern const float lbl_805A1CA8;
struct Vec { float x,y,z; };
struct Obj {
    char pad0[4]; int count; char pad8[0x28]; int value30;
    char pad34[0xc]; unsigned char a40,a41,a42,a43;
    Vec v; float f50; char pad54[2]; unsigned char a56,a57,a58,a59;
    char pad5a[0xe]; char m68[0x30]; char m98[0x30]; char padc8[0x20]; unsigned char e8,e9;
};
extern "C" void fn_80092418(Obj* p, unsigned int a) {
    p->e9=1;
    p->a40=a;
    Vec v = {lbl_805A1CA8,lbl_805A1CA8,lbl_805A1CA8};
    p->v=v;
    p->a56=0;
    p->f50=lbl_805A1CA8;
    if ((unsigned char)a==2) {
        p->a41=0;
        fn_801EC158(p->m68);
        fn_801EC158(p->m98);
        p->a57=0;
        p->a43=p->count;
        p->a42=p->count;
        p->a59=0;
        p->e8=1;
    } else {
        p->a43=0;
        p->a42=0;
        p->a57=0;
        p->a59=0;
    }
    p->value30=p->count-1;
}