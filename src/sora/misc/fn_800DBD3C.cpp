#include <gf/gf_resource_loader.h>
#include <gf/gf_archive.h>
#include <types.h>
#pragma force_active on

struct Obj800DBD3C {
    bool b0 : 1;
    bool b1 : 1;
    char pad1[0x1C - 0x1];
    void* m1C;
    void* m20;
    void* m24;
    void* m28;
    void* m2C;
    void* m30;
    void* m34;
    void* m38;
    void* m3C;
    void* m40;
    char pad44[0x48 - 0x44];
    void* m48;
    char pad4C[0x7C - 0x4C];
    void* m7C;
    void* m80;
    void* m84;
    char pad88[0x90 - 0x88];
    void* m90;
    char pad94[0x98 - 0x94];
    void* m98;
    char pad9C[0xC0 - 0x9C];
    gfArchive* mC0;
    gfResourceLoader* mC4;
};

extern "C" void fn_800DBD3C(Obj800DBD3C* p) {
    if (p->m1C) p->m1C = 0;
    if (p->m20) p->m20 = 0;
    if (p->m48) p->m48 = 0;
    if (p->m24) p->m24 = 0;
    if (p->m28) p->m28 = 0;
    if (p->m2C) p->m2C = 0;
    if (p->m30) p->m30 = 0;
    if (p->m34) p->m34 = 0;
    if (p->m38) p->m38 = 0;
    if (p->m7C) p->m7C = 0;
    if (p->m80) p->m80 = 0;
    if (p->m84) p->m84 = 0;
    if (p->m40) p->m40 = 0;
    if (p->m98) p->m98 = 0;
    if (p->m3C) p->m3C = 0;
    if (p->m90) p->m90 = 0;
    if (p->mC0) {
        delete p->mC0;
        p->mC0 = 0;
    }
    if (p->mC4) {
        delete p->mC4;
        p->mC4 = 0;
    }
    p->b1 = false;
}
