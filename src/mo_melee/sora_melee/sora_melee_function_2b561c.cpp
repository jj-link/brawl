#include <it/item.h>
#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

typedef unsigned long long U64;
union Pair { struct { float x, y; }; unsigned int bits[2]; };
class Component {
public:
    virtual void s0();
    virtual void s1();
    virtual Pair s2();
};
struct Self {
    char p0[0x38];
    int kind;
    char p1[0x50];
    Component a;
    char p2[0x48];
    Component b;
    char p3[0x1c];
    Component c;
    char pc;
    unsigned char cflag : 1;
    char p4[0x102];
    Component d;
    char pd;
    unsigned char dflag : 1;
    char p5[0xba];
    unsigned int current;
    unsigned int previous;
    char p6[4];
    int state;
    char p7[0x36];
    unsigned char count;
};
struct GroundBase { char pad[8]; };
class GroundVirtual : public GroundBase {
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual unsigned int get(unsigned int);
};
struct Access {
    char p0[8];
    BaseItem* item;
    char p1[0xcc];
    const soModuleEnumeration* modules;
};
extern "C" {
extern const float lbl_27_rodata_5EB8[];
int fn_27_2B823C(Self*, Access*, Pair*, int, bool);
float rsqrtf__Ff(float);
void fn_27_2B561C(Self* self, Access* access, int update) {
    const float* k = lbl_27_rodata_5EB8;
    const soModuleEnumeration* modules = access->modules;
    soGroundModule* ground = modules->m_groundModule;
    soWorkManageModule* work = modules->m_workManageModule;
    if (update) {
        work->offFlag(0x12000005);
        if (self->count) {
            --self->count;
            access->modules->m_groundModule->setCorrect((soGroundShapeImpl::CorrectKind)5, 0);
            access->modules->m_situationModule->setKind((SituationKind)2, false);
        }
    }
    self->current = 0;
    if (self->kind != -1) {
        self->current = ((GroundVirtual*)ground)->get(0);
        if (self->kind != 3) {
            if (self->state == 3 && self->current != self->previous && self->current &&
                !ground->isAttach(0)) {
                unsigned int flags = self->current;
                if (!(flags & 8)) {
                    if (flags & 1) ground->attach(1, 0);
                    else if (flags & 2) ground->attach(2, 0);
                    else if (flags & 4) ground->attach(4, 0);
                }
            }
            if (update) {
                int param = access->item->getParam((itValueAccesser::ParamInt)0x5b6c);
                if (self->current && self->current != self->previous && self->state != 3 && (param & 13)) {
                    Pair speed;
                    Pair result;
                    Pair initial = self->a.s2();
                    speed.bits[0] = initial.bits[0];
                    speed.bits[1] = initial.bits[1];
                    if (!(self->previous & 8)) {
                        Pair v = self->b.s2();
                        speed.x += v.x; speed.y += v.y;
                    }
                    if (self->dflag) {
                        Pair v = self->d.s2();
                        speed.x += v.x; speed.y += v.y;
                    }
                    if (self->cflag) {
                        Pair v = self->c.s2();
                        speed.x += v.x; speed.y += v.y;
                    }
                    result = speed;
                    int ret = fn_27_2B823C(self, access, &result, param, self->kind == 2);
                    if (ret) {
                        bool b = false;
                        bool a = false;
                        unsigned int prev = self->previous;
                        if ((prev & 6) && !(self->current & 6)) a = true;
                        if (a && (prev & ~6) == (self->current & ~6)) b = true;
                        if (!b) {
                            float sq = speed.x * speed.x + speed.y * speed.y;
                            float len;
                            if ((float)(double)nw4r::math::FAbs(sq) <= k[10]) len = k[1];
                            else len = sq * rsqrtf__Ff(sq);
                            if (len > k[11]) {
                                int id = work->getInt(0x10000018);
                                if (id) access->modules->m_soundModule->playSE((SndID)id, false, 0, 0);
                            }
                            sq = result.x * result.x + result.y * result.y;
                            if ((float)(double)nw4r::math::FAbs(sq) <= k[10]) len = k[1];
                            else len = sq * rsqrtf__Ff(sq);
                            if (len > k[11] && (!(ret & 1) || result.y > k[1]) && self->state != 3) {
                                work->onFlag(0x12000005);
                                access->modules->m_situationModule->setKind((SituationKind)2, false);
                            }
                        }
                    }
                }
            }
        }
    }
}
}