#pragma force_active on
typedef unsigned char u8;

namespace nw4r {
namespace g3d {
class G3dObj {
public:
    void Destroy();
};
} // namespace g3d
} // namespace nw4r

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_27_1FFCC(u8* self) {
    void* entry;
    if (!((self[0x24] >> 5) & 1)) {
        entry = *reinterpret_cast<void**>(self + 0x0);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            *reinterpret_cast<void**>(self + 0x0) = 0;
        }
        entry = *reinterpret_cast<void**>(self + 0x4);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            *reinterpret_cast<void**>(self + 0x4) = 0;
        }
        entry = *reinterpret_cast<void**>(self + 0x8);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            *reinterpret_cast<void**>(self + 0x8) = 0;
        }
        entry = *reinterpret_cast<void**>(self + 0xC);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            *reinterpret_cast<void**>(self + 0xC) = 0;
        }
        entry = *reinterpret_cast<void**>(self + 0x10);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            *reinterpret_cast<void**>(self + 0x10) = 0;
        }
        self[0x24] = (u8)(self[0x24] | 0x20);
    }
}
}
