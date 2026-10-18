#pragma force_active on
namespace nw4r {
namespace g3d {
class ScnMdl;
}
}

class gfSceneRoot {
public:
    enum LayerType {};
    void add(LayerType layer, nw4r::g3d::ScnMdl* mdl);
};

struct SrcInner {
    char pad[0xc];
    nw4r::g3d::ScnMdl* mdl;
};

struct SrcOuter {
    char pad[0x48];
    SrcInner* inner;
};

extern gfSceneRoot* g_gfSceneRoot;

extern "C" {
void fn_25_137C(SrcOuter* obj) {
    g_gfSceneRoot->add((gfSceneRoot::LayerType)8, obj->inner->mdl);
}
}
