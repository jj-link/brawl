#include <types.h>
#include <st/stage.h>
#include <gr/ground.h>
#pragma force_active on
#define V1(n) virtual void n();
#define V10(p) V1(p##0) V1(p##1) V1(p##2) V1(p##3) V1(p##4) V1(p##5) V1(p##6) V1(p##7) V1(p##8) V1(p##9)
struct GroundDispatchBase { char pad[0x3c]; };
class GroundDispatch : public GroundDispatchBase {
public:
    V10(a) V10(b) V10(c)
    V1(d0) V1(d1) V1(d2) V1(d3) V1(d4) V1(d5) V1(d6)
    virtual void startup(gfArchive*,u32,u32); V1(f38) virtual void setStageData(void*);
    V10(e) V10(f) V10(g) V10(h) V10(i) V10(j) V10(k)
    V1(m0) V1(m1) V1(m2) V1(m3)
    virtual void call114(void*); virtual void call115(void*); virtual void call116(void*); virtual void call117(u8);
};
extern "C" {
extern char lbl_48_data_0[];
Ground* fn_48_C28C(int,const char*,const char*);
void fn_48_924(Stage* self) {
    char* s=(char*)self;
    const char* d=lbl_48_data_0;
    u8 mode=*(u8*)(s+0x2c4);
    switch((int)mode) {
    case 0: return;
    case 1: {
        for (u32 i=0; i!=3; ++i) {
            Ground* base=fn_48_C28C(4,d+0xd8,d+0xec);
            if(!base)return;
            self->addGround(base);
            GroundDispatch* g=(GroundDispatch*)base;
            g->startup(*(gfArchive**)(s+0x1a0),0,0);
            g->setStageData(*(void**)(s+0x9c));
            g->call114(s+0x264);g->call115(s+0x1ec);g->call116(s+0x308);g->call117(i);
            self->createCollision(*(gfArchive**)(s+0x1a0),5,base);
        }
        Ground* base;
        for (u32 i=0; i!=3; ++i) {
            base=fn_48_C28C(4,d+0xd8,d+0x100);
            if(!base)return;
            self->addGround(base);
            GroundDispatch* g=(GroundDispatch*)base;
            g->startup(*(gfArchive**)(s+0x1a0),0,0);
            g->setStageData(*(void**)(s+0x9c));
            g->call114(s+0x27c);g->call115(s+0x1ec);g->call116(s+0x309);g->call117(i);
            self->createCollision(*(gfArchive**)(s+0x1a0),5,base);
        }
        break;
    }
    case 2: break;
    case 3: break;
    case 4: break;
    }
}
}
#undef V10
#undef V1