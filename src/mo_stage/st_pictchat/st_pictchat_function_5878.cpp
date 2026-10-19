#pragma force_active on
extern "C" {
void fn_27_1F299C(void* mgr, int id);
extern void* g_aiMgr;

struct Self {
    char pad[0x294];
    int a;
    int b;
};

void fn_73_5878(Self* self) {
    if (self->a != -1) {
        fn_27_1F299C(g_aiMgr, self->a);
    }
    if (self->b != -1) {
        fn_27_1F299C(g_aiMgr, self->b);
    }
    self->a = -1;
    self->b = -1;
}
}
