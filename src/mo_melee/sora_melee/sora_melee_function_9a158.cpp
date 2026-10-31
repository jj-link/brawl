#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Object {
    u8 pad0[0x48];
    u32 group;
    u8 pad4C[0x135 - 0x4C];
    u8 unused : 3;
    u8 visible : 1;
    u8 rest : 4;
};

struct ecMgr;
extern ecMgr* g_ecMgr;
extern "C" void setVisibleGroup__5ecMgrFUlbUlUl(ecMgr*, bool, u32, u32);

extern "C" void fn_27_9A158(Object* obj, bool visible) {
    if (obj->visible == visible) return;
    obj->visible = visible;
    setVisibleGroup__5ecMgrFUlbUlUl(g_ecMgr, obj->visible, obj->group | 4, 0x00FFFF04);
}
