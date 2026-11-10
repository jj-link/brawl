#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern void* g_GameGlobal;

extern "C" void fn_70_1C6C(u8* self) {
    void* obj = *(void**)((u8*)g_GameGlobal + 8);
    if (obj != 0) {
        u8* p = (u8*)obj;
        switch (p[0x1c]) {
        case 0: self[0x1d8] = 0; break;
        case 1: self[0x1d8] = 1; break;
        case 2: self[0x1d8] = 2; break;
        case 3: self[0x1d8] = 3; break;
        case 4: self[0x1d8] = 3; break;
        case 5: self[0x1d8] = 3; break;
        case 6: self[0x1d8] = 4; break;
        case 7: self[0x1d8] = 4; break;
        }

        s32 v = p[0x1c];
        switch (v) {
        case 4:
            self[0x1d9] = 0;
            return;
        case 5:
            self[0x1d9] = 1;
            return;
        case 7:
            self[0x1d9] = 1;
            return;
        }
    }
}
