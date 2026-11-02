#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

class GroundBase {
public:
    char pad0[0x3C];
};

class Ground : public GroundBase {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual s32 getNodeScaleByIndex(Vec3f*, u32, u32);

    char pad40[4];
    void** nodeArray;
};

extern "C" s32 getNodeScale__6GroundFP5Vec3fUlPCc(
    Ground* self, Vec3f* out, u32 index, const char* name)
{
    s32 found;
    u32 nodeIndex;

    if (name == 0) {
        found = 0;
    } else {
        nw4r::g3d::ResMdl mdl;
        void* resource = 0;
        void* model = self->nodeArray[index];

        if (model == 0) {
            found = 0;
        } else {
            resource = *(void**)((char*)model + 0xE8);
            mdl = nw4r::g3d::ResMdl(resource);
            if (resource == 0) {
                found = 0;
            } else {
                nw4r::g3d::ResNode res = mdl.GetResNode(name);
                if (!res.IsValid()) {
                    found = 0;
                } else {
                    nodeIndex = res.IsValid() ? res->m_nodeIndex : 0;
                    found = 1;
                }
            }
        }
    }

    if (found == 0)
        return 0;

    return self->getNodeScaleByIndex(out, index, nodeIndex);
}
