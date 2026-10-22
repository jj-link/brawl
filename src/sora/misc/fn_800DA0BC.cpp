#pragma force_active on
#include <types.h>

extern "C" {

extern void* getInstance__8ipSwitchFv(void);
extern unsigned char fn_800C8548(void);
extern void* g_GameGlobal;

bool fn_800DA0BC(void* arg0) {
    void* inst = getInstance__8ipSwitchFv();
    if (*(s32*)inst == 1) return false;

    void* p10 = *(void**)((char*)g_GameGlobal + 0x10);
    u8 flag = *(u8*)((char*)p10 + 6);
    if (flag != 0) {
        u8 idx = fn_800C8548();
        void* obj;
        if (idx == 0xFF) obj = NULL;
        else obj = (char*)arg0 + idx * 0x218 + 0x70;
        if (obj == NULL) return false;
        if (*(u8*)((char*)obj + 0x55) == 4) return false;
    }
    return true;
}

}
