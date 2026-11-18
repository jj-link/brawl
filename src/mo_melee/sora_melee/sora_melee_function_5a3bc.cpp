#include <types.h>
#pragma force_active on

struct Object_vptr_4_base { char pad[0x4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual u32 slot4();
    virtual unsigned long long slot5();
};

class ControllerImpl {
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

    char pad4[4];
    float x08;
    float y0c;
    float px10;
    float py14;
    float sx18;
    float sy1c;
    float subx20;
    float suby24;
    float psubx28;
    float psuby2c;
    float ssubx30;
    float ssuby34;
    float mag38;
    float pmag3c;
    float smag40;
    u32 flags44;
    u32 pflags48;
    u32 sflags4c;
    u32 pressed50;
    u32 released54;
    u8 hold[17][2];
    u8 c7a;
    s8 c7b;
    u8 c7c;
    s8 c7d;
    u8 c7e;
    s8 c7f;
    u8 c80;
    s8 c81;
    u8 c82;
    s8 c83;
    u8 c84;
    s8 c85;
    u8 c86;
    u8 c87;
    u8 init88;
    u8 flag89;
};

struct LinkRef {
    char pad0[0xc];
    u32 masks[17];
    float k50;
    float k54;
    float k58;
    float k5c;
    float k60;
};

struct Pair2f {
    float a;
    float b;
};

union U64Pair {
    unsigned long long u;
    Pair2f f;
};

static inline void bumpCounter(u8& v) {
    v = (u8)(v + 1);
    if (v > 0xFE) {
        v = 0xFE;
    }
}

extern "C" {
extern LinkRef unused_floats__29so_controller_module_link_ref;
float mtSqrtf__Ff(float);

void fn_27_5A3BC(ControllerImpl* self, Object_vptr_4* arg1, u32 arg2) {
    LinkRef& K = unused_floats__29so_controller_module_link_ref;
    Pair2f s;

    if (self->init88 == 0) {
        self->px10 = self->sx18;
        self->py14 = self->sy1c;
        self->psubx28 = self->ssubx30;
        self->psuby2c = self->ssuby34;
        self->pmag3c = self->smag40;
        self->pflags48 = self->sflags4c;
        self->init88 = 1;
    } else {
        self->px10 = self->x08;
        self->py14 = self->y0c;
        self->psubx28 = self->subx20;
        self->psuby2c = self->suby24;
        self->pmag3c = self->mag38;
        self->pflags48 = self->flags44;
    }

    arg1->slot1();
    U64Pair p;
    p.u = arg1->slot2();
    float k = K.k50;
    float y = p.f.b;
    float x = p.f.a;
    self->x08 = x;
    self->y0c = y;
    self->subx20 = k;
    self->suby24 = k;

    p.u = arg1->slot5();
    s.b = p.f.b;
    s.a = p.f.a;
    self->mag38 = (s.a > s.b) ? s.a : s.b;

    u32 flags = arg1->slot4();
    self->flags44 = flags;
    if (flags & 8) {
        float k54 = K.k54;
        self->flags44 = flags | 8;
        self->mag38 = k54;
    } else if (K.k50 != self->mag38) {
        self->flags44 = flags | 8;
    }

    u32 cur = self->flags44;
    u32 prev = self->pflags48;
    u32 changed = prev ^ cur;
    u32 newly = cur & changed;
    u32 gone = prev & changed;
    if (arg2 == 1) {
        self->pressed50 |= newly;
        self->released54 |= gone;
    } else {
        self->pressed50 = newly;
        self->released54 = gone;
    }

    bumpCounter(self->c82);

    if (self->x08 >= K.k58) {
        if (self->px10 >= K.k58) {
            bumpCounter(self->c7a);
            bumpCounter(self->c7e);
        } else {
            self->c82 = 0;
            self->c7e = 0;
            self->c7a = 0;
            self->c83 = 1;
            self->c7f = 1;
            self->c7b = 1;
        }
    } else {
        if (self->x08 <= K.k5c) {
            if (self->px10 <= K.k5c) {
                bumpCounter(self->c7a);
                bumpCounter(self->c7e);
            } else {
                self->c82 = 0;
                self->c7e = 0;
                self->c7a = 0;
                self->c83 = -1;
                self->c7f = -1;
                self->c7b = -1;
            }
        } else {
            self->slot14();
            self->c7e = 0xFE;
        }
    }

    bumpCounter(self->c84);

    if (self->y0c >= K.k58) {
        if (self->py14 >= K.k58) {
            bumpCounter(self->c7c);
            bumpCounter(self->c80);
        } else {
            self->c84 = 0;
            self->c80 = 0;
            self->c7c = 0;
            self->c85 = 1;
            self->c81 = 1;
            self->c7d = 1;
        }
    } else {
        if (self->y0c <= K.k5c) {
            if (self->py14 <= K.k5c) {
                bumpCounter(self->c7c);
                bumpCounter(self->c80);
            } else {
                self->c84 = 0;
                self->c80 = 0;
                self->c7c = 0;
                self->c85 = -1;
                self->c81 = -1;
                self->c7d = -1;
            }
        } else {
            self->slot15();
            self->c80 = 0xFE;
        }
    }

    float f30 = mtSqrtf__Ff(self->x08 * self->x08 + self->y0c * self->y0c);
    float f31 = mtSqrtf__Ff(self->px10 * self->px10 + self->py14 * self->py14);
    float thr = mtSqrtf__Ff(K.k60);
    if (f30 >= thr) {
        if (f31 >= thr) {
            bumpCounter(self->c86);
        } else {
            self->c86 = 0;
        }
    } else {
        self->slot42();
    }

    if (self->mag38 >= K.k58) {
        if (self->pmag3c >= K.k58) {
            bumpCounter(self->c87);
        } else {
            self->c87 = 0;
        }
    } else {
        self->slot43();
    }

    u32 mask;
    for (u8 i = 0; i < 17; i++) {
        if ((s32)i <= -1 || (s32)i >= 0x11) {
            mask = 0;
        } else {
            mask = ((const u32*)((const char*)&K + 12))[i];
        }
        if (self->pressed50 & mask) {
            self->hold[i][0] = self->hold[i][1];
            self->hold[i][1] = 0;
        } else {
            if (self->hold[i][1] < 0xFE) {
                self->hold[i][1]++;
            }
        }
    }

    if (self->flag89 == 1) {
        self->sx18 = self->x08;
        self->sy1c = self->y0c;
        self->ssubx30 = self->subx20;
        self->ssuby34 = self->suby24;
        self->smag40 = self->mag38;
        self->sflags4c = self->flags44;
        self->init88 = 0;
        self->slot12();
    }
}
}
