#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern const float lbl_112_rodata_50;
Vec3f* fn_112_9F54(Vec3f*, float, float, float);
void fn_27_8AB14(void*, int, Vec3f*, Vec3f*, soModuleAccesser*);
}
template <int Offset> struct Slot {};
template <int Offset> inline unsigned char* energySlot(unsigned char* p, const Slot<Offset>&) { return p + Offset; }
extern "C" void fn_112_127D8(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    unsigned char* energy = energySlot(energies, Slot<0x10>());
    Vec3f b, a;
    fn_27_8AB14(energy, -1,
        fn_112_9F54(&b, lbl_112_rodata_50, lbl_112_rodata_50, lbl_112_rodata_50),
        fn_112_9F54(&a, lbl_112_rodata_50, lbl_112_rodata_50, lbl_112_rodata_50), accesser);
    energy[5] |= 0x80;
}