#pragma force_active on
struct S { char p[0x14]; unsigned char f14; char q[3]; float f18, f1c, f20, f24; char r[0x18]; int f40; char s[0x74]; unsigned char fb8; };
struct Root { char p[0x465]; unsigned char f465; };
extern "C" void fn_800A6CF8(S*);
extern "C" void fn_800A709C(S*, int);
extern "C" const float lbl_805A205C;
extern Root* g_gfSceneRoot;
extern "C" void fn_800A6B78(S* s) {
    fn_800A6CF8(s);
    s->f14 = 0;
    s->f1c = lbl_805A205C;
    s->f18 = lbl_805A205C;
    s->f24 = lbl_805A205C;
    s->f20 = lbl_805A205C;
    s->f40 = -1;
    fn_800A709C(s, -1);
    s->fb8 = 0;
    g_gfSceneRoot->f465 |= 0x20;
}
