#include <gf/gf_archive.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    char pad[0xe0];
    void* fieldE4;
};
struct IfManager { char pad[0x14]; Class_8042B6D0* scene; };
struct CopyC0 { int data[48]; };
struct Copy60 { int data[7]; float x, y; int rest[15]; };
struct Task {
    char pad0[0x2c];
    unsigned char flags;
    char pad2d[0xf];
    void* vtable;
    gfArchive* archive;
    char pad44[0x4c];
    void* scene;
    char pad94[4];
    unsigned char active;
    char pad99[0x38b];
    int state;
    char pad428[4];
    int last;
};
extern "C" {
extern char lbl_8045BB7C[];
extern char lbl_8045BB98[];
extern const CopyC0 lbl_80408F88;
extern const Copy60 lbl_80409048;
extern const float lbl_805A2668, lbl_805A266C, lbl_805A2670;
extern IfManager* g_IfMngr;
extern void* g_GameGlobal;
void fn_800F4C34(Task*, const char*, int, int, int);
void fn_8006C620(void*);
void* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_800F4F34(Task*, CopyC0*, int);
void fn_800F5084(Task*, void*, Copy60*);
int fn_8004D9E8(void*);
}
extern "C" Task* fn_800F6FB4(Task* self, int arg) {
    fn_800F4C34(self, lbl_8045BB7C, arg, 0, 0x84);
    self->vtable = lbl_8045BB98;
    fn_8006C620(self->archive->getData((ARCNodeType)1, 0x3ee, 0xfffe));
    self->state = 6;
    CopyC0 a = lbl_80408F88;
    self->scene = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)15), 0, 9);
    self->flags &= ~2;
    fn_800F4F34(self, &a, 8);
    Class_8042B6D0* scene = g_IfMngr->scene;
    scene->fn_801B2EEC(scene->fieldE4, self->scene);
    self->active = 1;
    float x = lbl_805A2668;
    float y = lbl_805A266C;
    int id = 0x3f0;
    if (!fn_8004D9E8(g_GameGlobal)) {
        id = 0x3f1;
        x = lbl_805A2670;
    }
    void* data = self->archive->getData((ARCNodeType)1, id, 0xfffe);
    Copy60 b = lbl_80409048;
    b.x = x;
    b.y = y;
    fn_800F5084(self, data, &b);
    self->last = -1;
    return self;
}