#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Vec3f;
class soResourceModule;
enum itKind { itKind_Dummy };

extern "C" void* fn_27_2A66B8(
    void*, Vec3f*, Vec3f*, float, itKind, u32, int, int,
    soResourceModule*, u8, int, int, int, int
);
extern "C" void fn_27_28FC34(void*, void*);
extern "C" const float lbl_27_rodata_5D60;

extern "C" void* fn_27_2A9DB8(
    void* self, Vec3f* pos, int ownerId, void* arg
) {
    void* result = fn_27_2A66B8(
        self, pos, pos, lbl_27_rodata_5D60, (itKind)0x23,
        0, ownerId, -1, 0, 0, 0xFFFF, 0, 0xFFFF, 0x14
    );
    if (result) {
        fn_27_28FC34(result, arg);
        return *(void**)((char*)result + 0x8BC);
    }
    return 0;
}
