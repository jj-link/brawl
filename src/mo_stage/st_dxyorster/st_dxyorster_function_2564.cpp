#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_76_2564(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->getNodeIndex((u32*)((char*)self + 0x178), 0, "KurukuruBlockA");
    self->getNodeIndex((u32*)((char*)self + 0x17C), 0, "KurukuruBlockB");
    self->getNodeIndex((u32*)((char*)self + 0x180), 0, "KurukuruBlockC");
    self->getNodeIndex((u32*)((char*)self + 0x184), 0, "KurukuruBlockD");
    self->getNodeIndex((u32*)((char*)self + 0x188), 0, "KurukuruBlockE");
    self->getNodeIndex((u32*)((char*)self + 0x18C), 0, "KurukuruBlockF");
    self->getNodeIndex((u32*)((char*)self + 0x190), 0, "KurukuruBlockG");
    self->getNodeIndex((u32*)((char*)self + 0x194), 0, "KurukuruBlockH");
    self->getNodeIndex((u32*)((char*)self + 0x198), 0, "KurukuruBlockI");
    return result;
}
