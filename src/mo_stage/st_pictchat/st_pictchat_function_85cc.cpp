#pragma force_active on
extern void* g_aiMgr;

extern "C" {
void fn_27_1F299C(void* mgr, int id);
void fn_73_85CC(struct StPictchatSelf* self);
}

struct StPictchatSelf {
    char pad[0x2a0];
    int a;
    int b;
};

extern "C" void fn_73_85CC(StPictchatSelf* self) {
    if (self->a != -1) {
        fn_27_1F299C(g_aiMgr, self->a);
    }
    if (self->b != -1) {
        fn_27_1F299C(g_aiMgr, self->b);
    }
    self->a = -1;
    self->b = -1;
}
