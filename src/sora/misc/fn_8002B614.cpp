#pragma force_active on
class gfPadSystem;
extern gfPadSystem* g_gfPadSystem;

class gfPadSystem {
public:
    unsigned char pad0[0x35];
    unsigned char flags35;
    unsigned char pad1[0xb6c - 0x36];
    int field_b6c;

    void wpadGameDataCallback(int value);
};

void gfPadSystem::wpadGameDataCallback(int value) {
    gfPadSystem* sys = g_gfPadSystem;
    sys->field_b6c = value;
    sys->flags35 |= 0x80;
}
