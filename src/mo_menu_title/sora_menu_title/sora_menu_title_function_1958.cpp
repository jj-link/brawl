#pragma force_active on
struct Inner {
    char pad[0x10];
    void* f10;
};

struct Outer {
    char pad[0x50];
    Inner* p50;
    char pad2[0x0C];
    int f60;
};

extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D1B8(void* a, int b, void* c);

void fn_24_1958(Outer* p) {
    fn_8000D1B8(g_gfSceneRoot, 8, p->p50->f10);
    p->f60 = 3;
}
}
