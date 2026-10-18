#pragma force_active on
namespace nw4r {
namespace g3d {
struct ScnMdl;
}
}

class gfSceneRoot {
public:
    enum LayerType { LAYER_8 = 8 };
    void add(LayerType layer, nw4r::g3d::ScnMdl* mdl);
};

extern gfSceneRoot* g_gfSceneRoot;

struct Inner {
    char pad[0x10];
    nw4r::g3d::ScnMdl* mdl;
};

struct Outer {
    char pad[0x50];
    Inner* inner;
};

extern "C" {
void fn_24_2E80(Outer* p) {
    g_gfSceneRoot->add(gfSceneRoot::LAYER_8, p->inner->mdl);
}
}
