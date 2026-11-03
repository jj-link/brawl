#include <types.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_2_rodata_FC8[];
void fn_1_7EA4(void*, void*);
void fn_1_7EB8(void*, void*);
void setFrameNode__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);

struct ObjData {
    void* field0;             /* 0x00 */
    char padA[0x70];         /* 0x04 */
    void* model;             /* 0x74 */
    char padB[0xEC];         /* 0x78 */
    void* msg;               /* 0x164 */
    char padC[0x50];         /* 0x168 */
    int state;               /* 0x1b8 */
};
struct ModelData {
    char pad[0x10];
    void* field10;           /* 0x10 */
};
struct Self {
    char pad[0x40];
    ObjData* obj;            /* 0x40 */
};

void fn_2_31EB8(void* self_, int arg1, int arg2) {
    const float* base = (const float*)lbl_2_rodata_FC8;
    Self* f = (Self*)self_;

    if (f->obj->state != 0) {
        fn_1_7EB8(f->obj->field0, ((ModelData*)f->obj->model)->field10);
        f->obj->state = 0;
    }
    f->obj->state = arg1;

    void* model = f->obj->model;
    float fl;
    switch (arg1) {
    case 1:
        switch (f->obj->state) {
        case 1: fl = base[0x10c]; break;
        case 3: fl = base[0x13a]; break;
        }
        setFrameNode__8MuObjectFf(model, fl);
        setFrameVisible__8MuObjectFf(model, fl);
        break;
    case 2:
        fl = base[0x13b];
        setFrameNode__8MuObjectFf(model, fl);
        setFrameVisible__8MuObjectFf(model, fl);
        break;
    case 3:
        switch (f->obj->state) {
        case 1: fl = base[0x10c]; break;
        case 3: fl = base[0x13a]; break;
        }
        setFrameNode__8MuObjectFf(model, fl);
        setFrameVisible__8MuObjectFf(model, fl);
        break;
    }
    fn_1_7EA4(f->obj->field0, ((ModelData*)model)->field10);
    printIndex__5MuMsgFUlUlPv(f->obj->msg, 0x17, (unsigned long)arg2, 0);
}
}