#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" int fn_81_5D4C(grGimmick* self) {
    int result = self->grGimmick::setNode();
    self->Ground::getNodeIndex((u32*)((char*)self + 0x180), 0, "PokemonTrainer1N");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x184), 0, "PokemonTrainer2N");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x188), 0, "PokemonTrainer3N");
    self->Ground::getNodeIndex((u32*)((char*)self + 0x18C), 0, "PokemonTrainer4N");
    return result;
}
