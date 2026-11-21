#include <gr/gr_yakumono.h>
#include <st/st_trigger.h>
#include <so/area/so_area_module_impl.h>
#pragma force_active on

struct Quad { float a,b; union { float c; float d; }; Quad(float a_, float b_, float c_, float d_) : a(d_), b(c_), c(b_) { d = a_; } };
struct Info { char pad[0x20]; float a, b, c, d; };
struct Base { char pad[0x3c]; };
#define V4(n) virtual void v##n##a(); virtual void v##n##b(); virtual void v##n##c(); virtual void v##n##d();
class Obj : public Base {
public:
    V4(0) V4(1) V4(2) V4(3) V4(4) V4(5) V4(6) V4(7) V4(8) V4(9)
    V4(10) V4(11) V4(12) V4(13) V4(14) V4(15) V4(16) V4(17) V4(18) V4(19)
    virtual void v80();
    virtual Info* target();
    char pad1[0x10c];
    Yakumono* yak;
    Info* info;
    unsigned char a, b;
    short c;
    int d, e, f;
    float x, y, z, w;
    soSet<soAreaData> set;
    ykAreaData area;
    char padArea[0x18];
    float* pos;
    unsigned char flag;
};

extern float lbl_50_rodata_150;

extern "C" void fn_50_9CBC(Obj* o) {
    if (o->pos != NULL) {
        if (o->flag == 1) {
            Quad p(lbl_50_rodata_150, o->pos[2], o->pos[1], o->pos[0]);
            ((grGimmick*)o)->setPos((Vec3f*)o->pos);
        } else {
            Info* i = o->target();
            o->info = i;
            if (i != NULL) {
                o->a = 0;
                o->b = 0x16;
                o->d = 0;
                o->e = 0;
                o->c = 0;
                o->f = 0;
                o->x = i->a;
                o->y = i->b;
                o->z = i->c;
                o->w = i->d;
                ((grYakumono*)o)->grYakumono::setAreaGimmick((soAreaData*)&o->a, &o->set, &o->area, false);
                if (o->yak != NULL) {
                    stTrigger* t = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x25, -1);
                    if (t != NULL) {
                        t->setObserveYakumono(o->yak);
                        o->flag = 1;
                    }
                }
            }
        }
    }
}
