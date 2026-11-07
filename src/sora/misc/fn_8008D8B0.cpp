#include <types.h>
#include <gf/gf_application.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct Matrix { u32 v[12]; };
struct Position { float x, y, z; };
struct Vec2 { float x, y; };

struct Node {
    char p0[0x34];
    Position pos;
    char p40[0x30];
    Position result;
    char p7c[0x34];
    float b0;
    char pb4[0x1c];
    float d0, d4;
    char pd8[4];
    Matrix dc;
    char p10c[0x30];
    Matrix m13c, m16c;
    char p19c[4];
    u32 index;
    char p1a4[0x5c];
    int end;
};

struct Self {
    Node** nodes;
    int count;
    char p8[5];
    u8 initModel, reset, init;
    char p10[0x10];
    u8 mode;
    char p21[3];
    int handle;
    char p28[4];
    int selected;
    char p30[8];
    int state;
    char p3c[0x28];
    u8 flag;
    char p65[0x84];
    u8 value;
};

struct Context {
    char pad[0x4c];
    int count;
    u8 flag;
};

struct Global {
    char pad[0x58];
    Context* ctx;
};

extern "C" Global* lbl_8049DEC8[9];
extern "C" char lbl_8059DBF9;
extern "C" const float lbl_805A1C98, lbl_805A1CA8;

extern "C" int fn_8008653C(Context*, Self*, char*);
extern "C" void fn_8008F084(Self*, Matrix*, nw4r::g3d::ResMdl*);
extern "C" void fn_80081DC4(Node*);
extern "C" void fn_80081EE0(Node*, Matrix*);
extern "C" void fn_80082130(Node*);
extern "C" void fn_8008674C(Context*, Vec2*, Vec2*);
extern "C" void fn_8003E388(Matrix*, Matrix*);
extern "C" void fn_8003E6DC(Matrix*, Position*);
extern "C" void fn_80083390(
    Context*, Node*, Node*, void*, int, bool, int, int,
    int, int, int, int, int, int, int, int);

extern "C" void fn_8008D8B0(
    Self* self, Matrix* matrices, nw4r::g3d::ResMdl* model,
    int start, int count)
{
    if (!self->init) {
        Context* ctx = lbl_8049DEC8[0]->ctx;
        self->handle = fn_8008653C(ctx ? ctx : 0, self, &lbl_8059DBF9);
        self->init = 1;
    }

    Context* ctx = lbl_8049DEC8[0]->ctx;
    (ctx ? ctx : 0)->flag = self->value;

    ctx = lbl_8049DEC8[0]->ctx;
    ctx = ctx ? ctx : 0;
    if (count > 1)
        ctx->count = count;
    else
        ctx->count = 1;

    if (!self->initModel) {
        nw4r::g3d::ResMdl local = *model;
        fn_8008F084(self, matrices, &local);
        self->initModel = 1;
    }

    if (((u8*)g_gfApplication)[0xed] & 1) {
        int i;
        int offset = start * 4;
        int end = self->count - 1;
        for (int j = start; j < self->count; ++j) {
            if (self->nodes[j]->end == 0) {
                end = j;
                break;
            }
        }

        if (self->reset) {
            i = start;
            if (start <= end) {
                for (; i <= end; ++i) {
                    nw4r::g3d::ResNodeData* data =
                        model->GetResNode(self->nodes[i]->index).ptr();
                    u32 id = data ? *(u32*)((char*)data + 0x10) : 0;
                    self->nodes[i]->dc = matrices[id];
                    fn_80081DC4(self->nodes[i]);
                }
            }
        }

        count = start;
        if (start <= end) {
            for (; count <= end; ++count) {
                nw4r::g3d::ResNodeData* data =
                    model->GetResNode(self->nodes[count]->index).ptr();
                u32 id = data ? *(u32*)((char*)data + 0x10) : 0;
                Matrix* m = &matrices[id];

                self->nodes[count]->m13c = *m;
                fn_80081EE0(self->nodes[count], m);
                self->nodes[count]->m16c = *m;
                fn_80082130(self->nodes[count]);

                float a = lbl_805A1CA8;
                float b = a;
                if (self->mode == 2) {
                    a = self->nodes[count]->d0;
                    b = self->nodes[count]->d4;
                }

                if ((self->state == 0 &&
                     lbl_805A1CA8 == self->nodes[count]->b0) ||
                    (self->mode == 2 && a >= b * lbl_805A1C98) ||
                    (self->state == 1 &&
                     lbl_805A1CA8 == self->nodes[count]->b0 &&
                     self->nodes[count]->end == 0)) {
                    self->nodes[count]->dc = *m;
                    fn_80081DC4(self->nodes[count]);
                }
            }
        }

        Context* context = lbl_8049DEC8[0]->ctx;
        context = context ? context : 0;

        float minx, maxx, maxy, miny;
        miny = lbl_805A1CA8;
        maxy = miny;
        maxx = miny;
        minx = miny;
        int first = 0;

        for (int j = end; j >= start; --j) {
            Position pos = {
                self->nodes[j]->pos.x,
                self->nodes[j]->pos.y,
                self->nodes[j]->pos.z
            };
            if (!first) {
                maxx = pos.x;
                first = 1;
                minx = pos.x;
                miny = pos.y;
                maxy = pos.y;
            } else {
                if (pos.x < minx)
                    minx = pos.x;
                else if (maxx < pos.x)
                    maxx = pos.x;

                if (pos.y < miny)
                    miny = pos.y;
                else if (maxy < pos.y)
                    maxy = pos.y;
            }
        }

        Vec2 lo, hi;
        hi.x = maxx;
        hi.y = miny;
        lo.x = minx;
        lo.y = maxy;
        fn_8008674C(context, &lo, &hi);

        Node* selected;
        if (self->selected == -1) {
            selected = 0;
        } else {
            selected = self->nodes[self->selected];
            Matrix tmp;
            Position copy;
            Position out;
            fn_8003E388(&selected->dc, &tmp);
            fn_8003E6DC(&tmp, &out);
            copy.x = out.x;
            copy.y = out.y;
            copy.z = out.z;
            selected->result = copy;
        }

        fn_80083390(
            context, *(Node**)((char*)self->nodes + offset),
            selected, (char*)self + 0x3c,
            0, self->state == 0, 0, 0, 0, self->mode,
            0, 0, 0, 0, self->flag, 0);
    }
}
