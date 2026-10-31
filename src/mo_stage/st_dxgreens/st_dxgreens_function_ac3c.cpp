#pragma force_active on
struct Vec3f { float x, y, z; };

extern void* g_ecMgr;

extern "C" {
void setEffect__5ecMgrF4EfIDP5Vec3f(void* mgr, int id, Vec3f* pos);
void fn_79_AC3C(char* self);
}

void fn_79_AC3C(char* self) {
    char* p = *(char**)(self + 0x160);
    int r5 = 0;
    int st = (unsigned char)p[0x19];
    switch (st) {
    case 0:
        r5 = 1;
        break;
    case 2:
        if ((unsigned char)self[0x164] == 1) {
            r5 = 1;
        }
        break;
    default:
        break;
    }
    if (r5 == 0) {
        return;
    }
    p[0x19] = 3;
    char* q = *(char**)(self + 0x160);
    if ((unsigned char)q[0x1a] == 1) {
        setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5e0003, (Vec3f*)q);
    } else {
        setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5e0004, (Vec3f*)q);
    }
}
