#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct Vec3f;
class soResourceModule;
enum itKind { itKind_Dummy };

extern "C" void fn_27_2A66B8(void* self, Vec3f* a, Vec3f* b, float c, itKind kind, u32 f, int g, int m1, soResourceModule* h, u8 i, int j, int k, int l, int m);

class itManager {
public:
    void createItem(Vec3f* a, Vec3f* b, float c, itKind kind, u32 f, int g, soResourceModule* h, u8 i, int j, int k, int l);
};

void itManager::createItem(Vec3f* a, Vec3f* b, float c, itKind kind, u32 f, int g, soResourceModule* h, u8 i, int j, int k, int l) {
    fn_27_2A66B8(this, a, b, c, kind, f, g, -1, h, i, j, k, l, 0x14);
}
