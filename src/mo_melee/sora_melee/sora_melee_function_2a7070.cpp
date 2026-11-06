#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct Vec3f;
class soResourceModule;
enum itKind { itKind_Dummy };

extern "C" void fn_27_2A66B8(
    void*, Vec3f*, Vec3f*, float, itKind, u32, int, int,
    soResourceModule*, u8, int, int, int, int
);
extern "C" const float lbl_27_rodata_5D5C;
extern "C" const float lbl_27_rodata_5D60;

class itManager {
public:
    void createItem(itKind kind, u32 f, int g, soResourceModule* h, u8 i, int j, int k, int l);
};

struct Vec3f {
    float x, y, z;
};

void itManager::createItem(itKind kind, u32 f, int g, soResourceModule* h, u8 i, int j, int k, int l) {
    Vec3f pos;
    pos.x = lbl_27_rodata_5D5C;
    pos.y = lbl_27_rodata_5D5C;
    pos.z = lbl_27_rodata_5D5C;
    fn_27_2A66B8(this, &pos, &pos, lbl_27_rodata_5D60, kind, f, g, -1, h, i, j, k, l, 0x14);
}
