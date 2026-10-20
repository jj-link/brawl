#pragma force_active on
struct ecMgr;
extern ecMgr* g_ecMgr;

extern "C" void fn_80060E20(ecMgr* mgr, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);

struct Obj48 {
    char pad[0x48];
    unsigned int flags;
};

extern "C" void fn_27_99EDC(Obj48* self, unsigned int a, unsigned int b, unsigned int c)
{
    fn_80060E20(g_ecMgr, self->flags | a, a | 0x00ffff00, b, c, 0);
}
