#include <mt/mt_vector.h>
#pragma force_active on

struct Pt { int x; int y; };

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC(const Vec2f&);
    virtual void fn_8005C198(const Vec2f&);
    virtual void fn_8005C17C(const Vec2f&);
    virtual void fn_8005C160();
    virtual void fn_8005C0BC(const Vec2f&);
    virtual void fn_8005C06C();
    virtual unsigned long long fn_8005C048();
    virtual unsigned long long fn_8005C02C();
    virtual unsigned long long fn_8005C010();
    virtual unsigned long long fn_8005BF6C();
    virtual void fn_8005BF1C();
    virtual void fn_8005BEF8();
};
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050();
    virtual void fn_801B3248();
    virtual void fn_801B3298(Class_8042EA48*);
};
struct ContactA {
    unsigned char pad[15];
    unsigned char unused : 4;
    unsigned char flag3 : 1;
    unsigned char flag2 : 1;
    unsigned char flag1 : 1;
    unsigned char flag0 : 1;
};
struct ContactB {
    unsigned char pad[0x54];
    unsigned char unused : 3;
    unsigned char enabled : 1;
    unsigned char rest : 4;
};
struct ContactC {
    unsigned char pad[0x2c];
    unsigned char enabled : 1;
    unsigned char rest : 7;
};
struct Contact {
    ContactA* a;
    ContactB* b;
    ContactC* c;
    unsigned int other;
    bool pair() const { return a && b; }
    bool exists() const { return pair() && c; }
    bool valid() const { return a && b && c; }
    bool ready() const {
        if (valid() && b->enabled && c->enabled)
            return true;
        return false;
    }
};
struct State {
    unsigned char pad0[0x60];
    Class_8042B6D0* module;
    unsigned char pad64[8];
    union {
        struct { unsigned int upper : 8; unsigned int rest : 24; };
        struct { unsigned char pad6c; unsigned char mask : 8; unsigned short lower; };
    };
    unsigned char pad70;
    unsigned char flags71;
    unsigned char pad72[0xd4 - 0x72];
    Contact contacts[4];
    bool valid(unsigned char i) const {
        return contacts[i].pair() && contacts[i].c;
    }
};
struct Object {
    unsigned char pad0[0x18];
    State* state;
    unsigned char pad1c[0x2bc - 0x1c];
    Class_8042EA48* shape;
    Class_8042EA48* result;
};
struct Segment { Vec2f a,b; int kind; };
extern "C" {
void fn_80134468(State*, int);
void fn_80133F24(State*);
void fn_80111968(ContactC*, Segment*, ContactA*, int);
void fn_800408C4(Segment*, const Pt*, Pt*);
void fn_8004094C(Segment*, const Pt*, Pt*);
void fn_80119D1C(Contact*, const Pt*, Pt*, Pt*);
}
extern "C" void fn_8011B700(Object* obj) {
    int bit;
    unsigned char mask = obj->state->mask;
    unsigned int i;
    for (i = 0; i <= 3; ++i) {
        bit = 1 << (unsigned char)i;
        if (mask & bit) {
            Contact* contact = &obj->state->contacts[(unsigned char)i];
            if (!contact->exists() || !contact->ready()) {
                fn_80134468(obj->state, (unsigned char)i);
                mask &= ~bit;
            }
        }
    }
    if (mask) {
        if ((mask & 1) && obj->state->contacts[0].valid() &&
            !obj->state->contacts[0].a->flag1) mask &= 0xfe;
        if ((mask & 2) && obj->state->contacts[1].valid() &&
            !obj->state->contacts[1].a->flag2) mask &= ~2u;
        if ((mask & 4) && obj->state->contacts[2].valid() &&
            !obj->state->contacts[2].a->flag3) mask &= ~4u;
        if ((mask & 8) && obj->state->contacts[3].valid() &&
            !obj->state->contacts[3].a->flag0) mask &= ~8u;
    }
    obj->state->mask = mask;
    if (!mask) {
        fn_80133F24(obj->state);
        obj->state->upper = 0;
        fn_80134468(obj->state, 3);
        return;
    }
    if (obj->state->flags71 & 1) {
        Pt output, extra;
        Pt after0, after1, after2, after3;
        for (unsigned int i = 0; i < 4; ++i) {
            if (mask & (1 << (unsigned char)i)) {
                Contact* contact = &obj->state->contacts[(unsigned char)i];
                switch ((int)(unsigned char)i) {
                case 0: {
                    Segment line;
                    fn_80111968(contact->c, &line, contact->a, 0);
                    Pt initial;
                    *(unsigned long long*)&initial = obj->shape->fn_8005BF6C();
                    Pt hit;
                    Pt pos = initial;
                    fn_800408C4(&line, &pos, &hit);
                    obj->shape->fn_8005C0BC(*(Vec2f*)&hit);
                    *(unsigned long long*)&after0 = obj->shape->fn_8005BF6C();
                    fn_80119D1C(contact, &after0, &output, &extra);
                    obj->result->fn_8005C0BC(*(Vec2f*)&output);
                    break;
                }
                case 1: {
                    Segment line;
                    fn_80111968(contact->c, &line, contact->a, 0);
                    Pt initial;
                    *(unsigned long long*)&initial = obj->shape->fn_8005C02C();
                    Pt hit;
                    Pt pos = initial;
                    fn_8004094C(&line, &pos, &hit);
                    obj->shape->fn_8005C198(*(Vec2f*)&hit);
                    *(unsigned long long*)&after1 = obj->shape->fn_8005C02C();
                    fn_80119D1C(contact, &after1, &output, &extra);
                    obj->result->fn_8005C198(*(Vec2f*)&output);
                    break;
                }
                case 2: {
                    Segment line;
                    fn_80111968(contact->c, &line, contact->a, 0);
                    Pt initial;
                    *(unsigned long long*)&initial = obj->shape->fn_8005C010();
                    Pt hit;
                    Pt pos = initial;
                    fn_8004094C(&line, &pos, &hit);
                    obj->shape->fn_8005C17C(*(Vec2f*)&hit);
                    *(unsigned long long*)&after2 = obj->shape->fn_8005C010();
                    fn_80119D1C(contact, &after2, &output, &extra);
                    obj->result->fn_8005C17C(*(Vec2f*)&output);
                    break;
                }
                case 3: {
                    Segment line;
                    fn_80111968(contact->c, &line, contact->a, 0);
                    Pt initial;
                    *(unsigned long long*)&initial = obj->shape->fn_8005C048();
                    Pt hit;
                    Pt pos = initial;
                    fn_800408C4(&line, &pos, &hit);
                    obj->shape->fn_8005C1BC(*(Vec2f*)&hit);
                    *(unsigned long long*)&after3 = obj->shape->fn_8005C048();
                    fn_80119D1C(contact, &after3, &output, &extra);
                    obj->result->fn_8005C1BC(*(Vec2f*)&output);
                    break;
                }
                }
                obj->state->module->fn_801B3298(obj->result);
                return;
            }
        }
    }
}
