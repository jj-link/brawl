#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct Matrix { u32 v[12]; };
struct Node {
    char pad[0xdc];
    Matrix dc;
    char pad10c[0x94];
    u32 index;
};
struct Self {
    Node** nodes;
    int count;
    char pad8[5];
    u8 initModel, reset, init;
    char pad10[0x10];
    u8 mode;
    char pad21[3];
    int handle;
};
struct Context;
struct Global { char pad[0x58]; Context* ctx; };
extern "C" Global* lbl_8049DEC8[9];
extern "C" char lbl_8059DC09;
extern "C" int fn_8008653C(Context*, Self*, char*);
extern "C" void fn_8008F084(Self*, Matrix*, nw4r::g3d::ResMdl*);
extern "C" void fn_80081DC4(Node*);

extern "C" void fn_800957FC(Self* self, Matrix* matrices, nw4r::g3d::ResMdl* model)
{
    if (self->mode) {
        if (!self->init) {
            Context* ctx = lbl_8049DEC8[0]->ctx;
            self->handle = fn_8008653C(ctx ? ctx : 0, self, &lbl_8059DC09);
            self->init = 1;
        }
        if (!self->initModel) {
            nw4r::g3d::ResMdl local = *model;
            fn_8008F084(self, matrices, &local);
            self->initModel = 1;
        }
        if (self->reset) {
            int i = 0;
            if (self->count > 0) {
                for (; i < self->count; ++i) {
                    nw4r::g3d::ResNodeData* data =
                        model->GetResNode(self->nodes[i]->index).ptr();
                    u32 id = data ? *(u32*)((char*)data + 0x10) : 0;
                    self->nodes[i]->dc = matrices[id];
                    fn_80081DC4(self->nodes[i]);
                }
            }
            self->reset = 0;
        }
    }
}