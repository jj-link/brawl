#pragma force_active on
#include <st/stage.h>
#include <st/st_data_container.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <sr/sr_common.h>

struct Entry { char pad[0x48]; unsigned char kind; unsigned char kind2; };
namespace Matching {
struct Base { char pad[0x3c]; };
class Gimmick : public Base {
public:
#define V(n) virtual void n();
    V(f0) V(f1) V(f2) V(f3) V(f4) V(f5) V(f6) V(f7) V(f8) V(f9)
    V(f10) V(f11) V(f12) V(f13) V(f14) V(f15) V(f16) V(f17) V(f18) V(f19)
    V(f20) V(f21) V(f22) V(f23) V(f24) V(f25) V(f26) V(f27) V(f28) V(f29)
    V(f30) V(f31) V(f32) V(f33) V(f34) V(f35) V(f36)
    virtual void startup(gfArchive*, u32, u32);
    V(g0) V(g1) V(g2) V(g3) V(g4) V(g5) V(g6) V(g7) V(g8) V(g9)
    V(g10) V(g11) V(g12) V(g13) V(g14) V(g15) V(g16) V(g17) V(g18) V(g19)
    V(g20) V(g21) V(g22) V(g23) V(g24) V(g25) V(g26) V(g27) V(g28) V(g29)
    V(g30) V(g31) V(g32) V(g33) V(g34) V(g35) V(g36) V(g37) V(g38) V(g39)
    V(g40) V(g41)
    virtual void setEntry(Entry*);
#undef V
};
}
struct AdventureStage : Stage { gfArchive* resource; };
extern "C" {
extern char lbl_40_data_2D8[];
Matching::Gimmick* fn_27_27C478(short, const char*);
void fn_40_AB50(AdventureStage* stage, u32 type, stDataMultiContainer* multi) {
    grCollData* collData;
    unsigned char kind2;
    Entry* entry;
    Matching::Gimmick* ground;
    stDataContainer* container;
    u32 index = 0;
    u32 i;
    while ((container = multi->searchContainer(type, index++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; ++i) {
            entry = (Entry*)container->getData(i);
            ground = fn_27_27C478((short)entry->kind, lbl_40_data_2D8);
            if (ground) {
                stage->addGround((Ground*)ground);
                ground->setEntry(entry);
                ground->startup(stage->resource, 0, 0);
                kind2 = entry->kind2;
                if (kind2 != 0xFF) {
                    collData = (grCollData*)::operator new(0x28, Heaps::StageInstance);
                    if (collData) {
                        stage->testCollDataInit(stage->resource, collData, kind2);
                        stage->setCollision(grCollision::create(stage, collData, (Ground*)ground, 1));
                    }
                    ::operator delete(collData);
                }
            }
        }
    }
}
}