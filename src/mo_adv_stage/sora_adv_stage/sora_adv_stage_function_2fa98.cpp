#pragma force_active on
struct Mtx {
    float m[3][4];
};

struct Child {
    char pad[0x15C];
    int state;
    unsigned char active;
};

struct Model {
    void* model;
};

struct Stage {
    char pad0[0x44];
    Model* models;
    char pad48[0x128];
    unsigned char flag;
    char pad171[3];
    Child* children[13];
    unsigned char count;

    typedef void (Stage::*Handler)(int*, Child*, float);
};

struct Table {
    Stage::Handler entries[4];
};

extern "C" {
extern const Table lbl_40_rodata_578;

void update__9grGimmickFf(Stage*, float);
void GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    void*, Mtx*, int, unsigned long);
void fn_8003E388(Mtx*, Mtx*);
void fn_27_26DD40(Child*, Mtx*);
void fn_40_2FC14(Stage*);
void fn_40_2FDC4(Stage*);
void fn_27_264DDC(Stage*);

void fn_40_2FA98(Stage* self, float delta) {
    update__9grGimmickFf(self, delta);

    Table table = lbl_40_rodata_578;

    for (unsigned char i = 0; i < self->count; ++i) {
        self->children[i]->active = 1;

        if (self->children[i]->state == 0) {
            Mtx b, a;
            GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
                self->models->model, &a, 1, i + 1);
            fn_8003E388(&a, &b);
            fn_27_26DD40(self->children[(int)i], &b);
        }

        int index = i;
        (self->*table.entries[self->children[i]->state])(
            &index, self->children[i], delta);
    }

    fn_40_2FC14(self);
    fn_40_2FDC4(self);

    if (self->flag) {
        self->flag = 0;
        fn_27_264DDC(self);
    }
}
}
