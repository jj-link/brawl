#pragma force_active on
typedef unsigned char u8;

class gfSceneRoot {
public:
    void updateZoneLightSet(u8 arg0, u8 arg1);
};

void gfSceneRoot::updateZoneLightSet(u8 arg0, u8 arg1) {
    u8* p = (u8*)this + arg0 * 12;
    u8 cur = p[0x6f];
    if (cur == arg1) {
        return;
    }
    p[0x70] = cur;
    p[0x6f] = arg1;
    p[0x71] = 0;
}
