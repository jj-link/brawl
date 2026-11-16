#pragma force_active on
#include <nw4r/g3d/g3d_scnmdl.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11(int arg, nw4r::g3d::ScnMdl* mdl);
    char pad[0xe4 - 4];
    int field;
};

struct LayerEntry {
    Object_vptr_0* obj;
    char pad[0xa - 4];
    unsigned short cnt;
    char pad2[0x18 - 0xc];
};

class gfSceneRoot {
public:
    enum LayerType { Layer_Ground = 0 };
    char pad[0x390];
    LayerEntry table[16];
    int add(LayerType lt, nw4r::g3d::ScnMdl* scnMdl);
};

int gfSceneRoot::add(LayerType lt, nw4r::g3d::ScnMdl* scnMdl) {
    int ret = 0;
    Object_vptr_0* obj = table[(int)lt].obj;
    if (obj != 0) {
        ret = obj->slot11(obj->field, scnMdl);
        if (ret != 0) {
            table[(int)lt].cnt++;
        }
    }
    return ret;
}
