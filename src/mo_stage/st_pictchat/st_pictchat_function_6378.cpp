#include <gr/ground.h>
#include <snd/snd_3d_generator.h>
#include <snd/snd_system.h>
#pragma force_active on
struct PcBase { char pad[0x3c]; };
struct PcObject : PcBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66();
    virtual float getMotionFrame(unsigned long);
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(); virtual void slot79();
    virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84(); virtual void slot85(); virtual void slot86(); virtual void slot87();
    virtual void slot88(); virtual void slot89(); virtual void slot90(); virtual void slot91();
    virtual void slot92(); virtual void slot93(); virtual void slot94(); virtual void slot95();
    virtual void slot96(); virtual void slot97(); virtual void slot98(); virtual void slot99();
    virtual void slot100(); virtual void slot101(); virtual void slot102(); virtual void slot103();
    virtual void slot104(); virtual void slot105(); virtual void slot106(); virtual void slot107();
    virtual void slot108(); virtual void slot109(); virtual void slot110(); virtual void slot111();
    virtual void slot112(); virtual void slot113(); virtual void slot114(); virtual void slot115();
    virtual void slot116(); virtual void slot117(); virtual void slot118(); virtual void slot119();
    virtual void slot120(); virtual void slot121(); virtual void slot122(); virtual void slot123();
    virtual void slot124(); virtual void slot125(); virtual void slot126();
    virtual void change(int, int, int, float*);
};
struct Entry { char pad[0x54]; union { unsigned char raw; struct { unsigned char a : 1, b : 1, c : 1, d : 1, e : 1, f : 1, g : 1, h : 1; } bits; }; };
struct Obj : PcObject {
    char pad40[0x110]; unsigned char state; char pad151[0xb];
    unsigned char* action; char pad160[4]; unsigned char* count; char pad168[0xc];
    Entry** entries; unsigned char num; char pad179[0x117]; float frame;
    snd3DGenerator sound; int handle;
};
extern "C" void fn_73_6378(Obj* self) {
    if (!(self->getMotionFrame(0) < self->frame)) {
        *self->action = 0x1d;
        self->change(2, 0, 1, &self->frame);
        ((Ground*)self)->setEnableCollisionStatus(false);
        if (self->handle != -1) { self->sound.stopSE(self->handle, 0); self->handle = -1; }
        g_sndSystem->playSE((SndID)0x1d1f, 0, 0, 0, -1);
        if (self->entries != 0) {
            unsigned int n = self->num;
            for (unsigned int i = 0; i != n;) {
                Entry* e = self->entries[i];
                i++;
                e->bits.a = 0; e->bits.d = e->bits.a; e->bits.b = e->bits.d;
            }
        }
        --*self->count;
        self->state = 4;
    }
}
