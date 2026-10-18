#pragma force_active on
extern "C" {
void fn_27_1F299C(void* mgr, int id);
extern void* g_aiMgr;

struct Self {
    char pad[0x294];
    int a;
    int b;
    int c;
    int d;
};

void fn_73_8C50(Self* self) {
    if (self->a != -1) {
        fn_27_1F299C(g_aiMgr, self->a);
    }
    if (self->b != -1) {
        fn_27_1F299C(g_aiMgr, self->b);
    }
    if (self->c != -1) {
        fn_27_1F299C(g_aiMgr, self->c);
    }
    if (self->d != -1) {
        fn_27_1F299C(g_aiMgr, self->d);
    }
    self->a = -1;
    self->b = -1;
    self->c = -1;
    self->d = -1;
}
}
