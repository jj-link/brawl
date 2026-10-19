#pragma force_active on
extern "C" {
struct AiMgr;
extern AiMgr* g_aiMgr;
void fn_27_1F299C(AiMgr*, int);
}

struct Self {
    int pad[0x2B4 / 4];
    int id;
};

extern "C" void fn_73_73EC(Self* self) {
    if (self->id != -1) {
        fn_27_1F299C(g_aiMgr, self->id);
        self->id = -1;
    }
}
