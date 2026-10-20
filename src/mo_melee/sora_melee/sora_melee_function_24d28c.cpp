#pragma force_active on
typedef unsigned char u8;

struct Menu {
    u8 pad00[0x44];
    u8* entries;
    u8 pad48[0x84];
    u8* players;
    u8 padD0[0x34];
    int count;
    u8 pad108[0x11C];
    u8 enabled;
};

extern "C" u8* g_muWifiInterfaceTask;

extern "C" void fn_27_24D28C(Menu* self) {
    if (!self->enabled)
        return;

    u8* dest = g_muWifiInterfaceTask + 0xFDF;
    for (int i = 0; i < self->count; ++i) {
        u8* entry = self->entries + i * 0x5C;
        if (entry[0x99] != 3) {
            int index = entry[0x9B];
            if (index >= 0 && index < 4) {
                dest[i] = self->players[index * 0x2AC + 0x33];
            }
        }
    }
}
