#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct Vec3f;
class soResourceModule;
enum itKind { itKind_Dummy };

extern "C" void fn_27_2A66B8(void* self, Vec3f* a, Vec3f* b, float c, itKind kind, u32 f, int g, int m1, soResourceModule* h, u8 i, int j, int k, int l, int m);

class itManager {
public:
    void createItem(Vec3f* pos, float lr, itKind kind, u32 variation, int createOwnerTaskId, soResourceModule* resourceModule, u8 groupNo, int brresId, int texResIndex, int texResId);
};

void itManager::createItem(Vec3f* pos, float lr, itKind kind, u32 variation, int createOwnerTaskId, soResourceModule* resourceModule, u8 groupNo, int brresId, int texResIndex, int texResId) {
    fn_27_2A66B8(this, pos, pos, lr, kind, variation, createOwnerTaskId, -1, resourceModule, groupNo, brresId, texResIndex, texResId, 0x14);
}
