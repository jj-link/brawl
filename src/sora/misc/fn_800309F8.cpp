#include <gf/gf_heap_manager.h>
#include <gf/gf_shutdown_manager.h>
#pragma force_active on
extern "C" void fn_8014E520(void*, int);
struct O {
    char p0[0x8c];
    void* f8c; void* f90; void* f94; void* f98; void* f9c; void* fa0;
    char p1[0x4c];
    int ff0; int ff4;
    unsigned char ff8_0:1; unsigned char ff8_1:1; unsigned char ff8_2:1; unsigned char ff8_3:2; unsigned char ff8_r:3;
    unsigned char ff9;
    char pfa[6];
    int f100; int f104; void* f108;
};
struct B { char p[8]; unsigned char u8; char p2[7]; };
extern B lbl_804953A0;
extern "C" int fn_800309F8(O* o, void* a, int k) {
    if (o->ff0 != 0) return 0;
    bool t = false;
    o->ff0 = 2;
    o->ff4 = 4;
    o->ff8_0 = 0;
    o->ff8_3 = 0;
    o->ff9 = 0;
    o->f100 = 0;
    o->ff8_1 = (k == 8);
    o->ff8_2 = (k == 7);
    t = k == 8 || k == 7;
    if (t) k = 0;
    o->f104 = k;
    o->f108 = a;
    o->fa0 = 0;
    if (o->f8c) { gfHeapManager::free(o->f8c); o->f8c = 0; }
    if (o->f90) { gfHeapManager::free(o->f90); o->f90 = 0; }
    if (o->f94) { gfHeapManager::free(o->f94); o->f94 = 0; }
    if (o->f9c) { fn_8014E520(o->f9c, 1); o->f9c = 0; }
    if (o->ff8_1 || o->f104 == 4) o->ff4 = 0;
    else if (o->f104 == 3) o->ff4 = 2;
    lbl_804953A0.u8 = 0;
    g_gfShutdownManager.unkC = 0;
    return 1;
}