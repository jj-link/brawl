#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on
struct Position { float x, y, z; };
struct Entry { unsigned int id; char pad[0x28]; Position pos; char rest[0x48]; };
struct Callback { void* vtable; Entry* data; unsigned int b, c; };
struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x88];
    Callback cb;
    char pade0[0x98];
    Position p0, p1, p2, p3, p4;
    char pad1b4[0x1c];
    unsigned int id0, id1, id2, id3, id4;
};
extern "C" void fn_66_33D0(Object* self) {
    Callback* cb = &self->cb;
    if (cb) {
        nw4r::g3d::ScnMdlSimple* model = self->models[0];
        if (model) {
            if (!model->m_calcWorldCallBack) {
                cb->c = 0;
                cb->data[0].id = self->id2;
                cb->data[1].id = self->id3;
                cb->data[2].id = self->id4;
                cb->data[3].id = self->id1;
                cb->data[4].id = self->id0;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = cb->data[0].id;
            }
            cb->data[0].pos = self->p2;
            cb->data[1].pos = self->p3;
            cb->data[2].pos = self->p4;
            cb->data[3].pos = self->p1;
            cb->data[4].pos = self->p0;
        }
    }
}