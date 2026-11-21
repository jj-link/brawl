#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

using nw4r::math::VEC3;
inline void scaleVec(VEC3* pos, float scale) { LocalScale((Vec*)pos, (Vec*)pos, scale); }

struct Matrix {
    float v[12];
};

class soNullable {
public:
    virtual void isNull();
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
    virtual void slot33(unsigned int, Matrix*);
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
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual unsigned int slot78();
    virtual void slot79();
    virtual void slot80();
    virtual unsigned int slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual float slot96();
    virtual void slot97();
    virtual void slot98(Matrix*, int);
};

struct Table {
    char pad[0xc];
    soNullable* other;
    char pad2[0x44];
    soNullable* model;
};

struct Owner {
    char pad[0xd8];
    Table* table;
};

struct Node {
    unsigned int id;
    char pad[0x24];
    int active;
};

struct Base {
    int a, b;
};

class Self : public Base {
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
    virtual VEC3 slot23(int);
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
    virtual unsigned int slot34(unsigned int);

    char pad0[0x30];
    char list[0xc];
    Node* current;
    char pad1[0x38];
    unsigned int saved;
    char pad2[0x20];
    unsigned char* states;
    char pad3[0x1c];
    Owner* owner;
};

extern "C" unsigned int fn_80047C0C(void*, unsigned int);
extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801EC158(void*);
extern "C" void fn_801A4DD0(void*, float, float, float);

extern "C" unsigned int fn_27_923C(Self* self, void** arg, unsigned int id) {
    unsigned int next = self->slot34(self->owner->table->model->slot81());
    unsigned int result = 0xffffffff;

    if (id == next) {
        if (fn_80047C0C(self->states, id) == 1) {
            Matrix matrix;
            self->owner->table->model->slot98(&matrix, 1);

            if ((unsigned int)&matrix)
                fn_801EC184(&matrix, *arg);
            else
                fn_801EC158(*arg);

            if (!(self->owner->table->model->slot78() & 8)) {
                VEC3 pos = self->slot23(0);
                const float scale = self->owner->table->model->slot96();
                scaleVec(&pos, scale);
                fn_801A4DD0(arg, pos.x, pos.y, pos.z);
            }

            self->states[id] = 1;
            self->owner->table->other->slot33(id, &matrix);
        }

        Node* node = fn_8015C1B0(self->list, self->current);
        if (node && node->id == id) {
            self->current = node;
            node = fn_8015C1B0(self->list, node);
            if (node && node->active)
                result = node->id;
        } else {
            result = self->saved;
        }
    } else {
        Node* node = fn_8015C1B0(self->list, self->current);
        if (node) {
            if (node->id != id) {
                result = node->id;
            } else if (node->active) {
                self->current = node;
                node = fn_8015C1B0(self->list, node);
                if (node && node->active)
                    result = node->id;
            }
        }

        if (next != 0xffffffff && id < next &&
            self->saved == 0xffffffff &&
            (result == 0xffffffff || next < result)) {
            self->saved = result;
            return next;
        }
    }

    if (result == 0xffffffff)
        self->current = 0;
    return result;
}
