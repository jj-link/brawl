#include <types.h>
#pragma force_active on

struct ftStateOwnerX {
    u8 pad[0x14];
    u8 unk14;
};

struct ftOwnerX {
    u8 pad[0x44];
    ftStateOwnerX* unk44;
};

struct GameGlobalX {
    u8 pad[0x3c];
    void* unk3c;
};

extern GameGlobalX* g_GameGlobal;

extern "C" void fn_27_24C6FC(ftOwnerX* self, void* arg);

extern "C" void fn_27_253168(ftOwnerX* self)
{
    u8 st = self->unk44->unk14;
    if (st >= 5 && st <= 10) {
        fn_27_24C6FC(self, g_GameGlobal->unk3c);
    }
}
