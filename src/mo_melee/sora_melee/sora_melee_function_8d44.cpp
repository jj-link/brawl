#include <so/model/so_model_module_impl.h>
#pragma force_active on

struct ModelData {
    unsigned int words[4];
    unsigned char flag;
};

struct ModelLayout {
    char pad[0x98];
    char scene[0x10];
    ModelData data;
    char padBC[8];
    unsigned char id;
};

extern "C" {
    void fn_800257C8(unsigned char id, gfSceneRoot::LayerType layer,
                     nw4r::g3d::ScnMdl* mdl);
    void fn_8000D06C(void* root, void* scene);
    extern unsigned char lbl_27_data_4A4;
}

void soModelModuleImpl::setScnMdl(nw4r::g3d::ScnMdl* mdl, void* data,
                                 gfSceneRoot::LayerType layer) {
    soModelModuleSimple::setScnMdl(mdl, data, layer);

    ModelLayout* self = (ModelLayout*)this;
    ModelData* src = (ModelData*)data;
    self->data.words[0] = src->words[0];
    self->data.words[1] = src->words[1];
    self->data.words[2] = src->words[2];
    self->data.words[3] = src->words[3];
    self->data.flag = src->flag;

    if (self->id != lbl_27_data_4A4) {
        fn_800257C8(self->id, layer, mdl);
    }

    if (getScnMdl(true) != 0) {
        fn_8000D06C(g_gfSceneRoot, self->scene);
    }
}
