#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

struct LayerPair { u8 layer; u8 index; };
struct LayerEntry {
    nw4r::g3d::ScnMdl* model;
    u8 active : 1;
    u8 flags : 7;
    u8 index;
    u8 padding[6];
};
struct SceneRoot {
    u8 padding[0x68];
    LayerEntry entries[10];
};

extern "C" LayerPair fn_80010190(SceneRoot* self, nw4r::g3d::ScnMdl* model)
{
    u8 i = 0;
    for (int n = 0; n < 10; ++n, ++i) {
        LayerEntry* entry = &self->entries[i];
        if (!entry->active) {
            entry->model = model;
            LayerPair pair;
            pair.layer = i;
            entry->active = 1;
            pair.index = entry->index;
            return pair;
        }
    }
    LayerPair pair;
    pair.layer = 0xff;
    pair.index = 0x14;
    return pair;
}
