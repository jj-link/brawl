#pragma force_active on
#include <types.h>
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

class Interface {
public:
    virtual void fn_49_1934();
    virtual void fn_49_19B4();
    virtual void fn_49_5D1C();
    virtual void fn_49_5D18();
    virtual void fn_49_5D14();
    virtual void fn_49_5D10();
    virtual void fn_49_1974(nw4r::g3d::ScnMdlSimple*);
    virtual void fn_49_39A0(float, float, float);
    virtual void fn_49_39B0(float, float, float);
};

struct Class_1350_base {
    char pad[0x158];
};

class Class_1350 : public Class_1350_base, public Interface {};

struct Data {
    u32 id;
    char pad[0x4c];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    Data* data;
    u32 b;
    u32 c;
};

struct Entry {
    char pad[0xc];
    float x, y, z, a, b, c;
    char pad24[0x10];
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x78];
    u32 index;
    u32 id;
    char padc8[8];
    Callback callback;
    char pade0[0xa8];
    u8 state;
    char pad189[0xcb];
    Entry* entries;
};

extern "C" void fn_8003F074(Matrix*, float, float, float);
extern "C" const float lbl_49_rodata_F8;
extern "C" const float lbl_49_rodata_58;

inline void rotateDegrees(Matrix* matrix, float angle) {
    matrix->rotY(lbl_49_rodata_F8 * angle);
}

extern "C" void fn_49_37D0(Object* self) {
    Callback* cb = &self->callback;
    if (cb) {
        nw4r::g3d::ScnMdlSimple* model = self->models[self->index];
        if (model) {
            if (!model->m_calcWorldCallBack) {
                cb->c = 0;
                cb->data->id = self->id;
                model->m_calcWorldCallBack =
                    (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = cb->data->id;
                ((Class_1350*)self)->fn_49_1974(model);
                *(void**)((char*)model + 0xd4) = (char*)self + 0x158;
            }

            Matrix m;
            fn_8003F074(&m,
                        self->entries[self->state].x,
                        self->entries[self->state].y,
                        self->entries[self->state].z);
            rotateDegrees(&m, self->entries[self->state].b);
            cb->data->matrix = m;

            ((Class_1350*)self)->fn_49_39A0(
                self->entries[self->state].x,
                self->entries[self->state].y,
                self->entries[self->state].z);
            ((Interface*)((char*)self + 0x158))->fn_49_39B0(
                self->entries[self->state].a,
                lbl_49_rodata_58,
                self->entries[self->state].c);
        }
    }
}
