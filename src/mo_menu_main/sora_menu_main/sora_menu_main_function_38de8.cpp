#pragma force_active on
extern "C" {
extern void* g_muWifiInterfaceTask;
extern void* g_gfHomeMenu;
int setBan__10gfHomeMenuFUlUl(void*, unsigned long, unsigned long);
int fn_80037BE4(void*);
void create__19muWifiInterfaceTaskFv();
int fn_2_38DE8(void* self);
}

int fn_2_38DE8(void* self) {
    if (g_muWifiInterfaceTask != 0) {
        return 1;
    }
    if (setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 1, 2) == 0) {
        return *(int*)((char*)self + 0x138);
    }
    if (fn_80037BE4(g_gfHomeMenu) == 0) {
        return *(int*)((char*)self + 0x138);
    }
    create__19muWifiInterfaceTaskFv();
    return 1;
}
