#pragma force_active on
struct Inner {
    char pad[0x58];
    void* f58;
};

struct Outer {
    void* f0;
    Inner* f4;
};

extern "C" {
extern void* g_aiMgr;
void fn_27_1F1AD4(void* mgr, void* obj, void* arg);

void fn_27_1246D4(Outer* self, void* arg) {
    fn_27_1F1AD4(g_aiMgr, self->f4->f58, arg);
}
}
