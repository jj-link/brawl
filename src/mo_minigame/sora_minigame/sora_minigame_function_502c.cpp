#include <mt/mt_matrix.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on

extern "C" {
extern void* lbl_20_bss_8;
extern void* lbl_805A0EC8;
extern const float lbl_20_rodata_50[];

void* fn_8027EA20(void*, unsigned int, int);
void fn_8027EABC(void*, void*, unsigned int, int);
void fn_802EC1C0(void*, void*, int);
void fn_802E1970(void*, void*);
void fn_802E18B0(void*, void*);
void setFrame__16gfModelAnimationFd(void*, double);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void fn_8003F074(Matrix*, float, float, float);
void fn_801AAF04(void*, int, Matrix*);
void fn_801AF9F4(void*);
}

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void* vf5();
    char pad4[4];
    void* other;
};

struct Item {
    char pad0[0x24];
    Inner* object;
    char pad28[0x18];
    int field40;
    int pad44;
    float field48;
    int field4c;
    int field50;
    int field54;
    char pad58[8];
    float field60;
    int pad64;
    float field68;
    float field6c;
};

struct Global {
    char pad[0x4dc];
    Item** items;
    int count;
};

struct Array {
    Item** data;
    int size;
    unsigned int capacity;
    unsigned int pad[1];
};

struct Locals {
    Array list;
};

inline void copyItems(Array* array, int size, Item** source) {
    int i = 0;
    Item** src = source;
    array->size = size;
    Item** dst = array->data;
    for (; i < size; ++i) {
        dst[i] = src[i];
    }
}

inline bool isOwned(const Array& a) { return (a.capacity & 0x80000000) == 0; }
inline void dealloc(Array& a) { fn_8027EABC(lbl_805A0EC8, a.data, a.capacity << 2, 0x15); }
inline void freeItems(Array& a) {
    if (isOwned(a)) dealloc(a);
}

struct Self {
    char pad0[0x24];
    void* object;
    int pad28;
    void* model;
    void* anim;
    float x;
    float y;
    float z;
    int field40;
    int field44;
    float field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    float field5c;
    float field60;
    int pad64;
    float field68;
    float field6c;
};

extern "C" void fn_20_502C(Self* self) {
    const float* ro = lbl_20_rodata_50;
    void* g = lbl_20_bss_8;
    Locals loc;
    unsigned int mtx[12];
    Array& list = loc.list;
    list.data = 0;
    list.size = 0;
    list.capacity = 0x80000000;
    int capacity = list.capacity & 0x3fffffff;
    int count = ((Global*)g)->count;
    if (capacity < count) {
        if (!(list.capacity & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, list.data, capacity * 4, 0x15);
        }
        list.data = (Item**)fn_8027EA20(lbl_805A0EC8, ((Global*)g)->count * 4, 0x15);
        list.capacity = ((Global*)g)->count | (list.capacity & 0x40000000);
    }
    copyItems(&list, ((Global*)g)->count, ((Global*)g)->items);

    self->object = list.data[0]->object->vf5();
    fn_802EC1C0(list.data[0]->object->other, self->object, 1);

    g = self->object;
    fn_802E1970(g, (char*)self + 0x18);
    char* q = (char*)&self->object - 0xc;
    if (q != 0) q = q + 4;
    fn_802E18B0(g, q);

    self->field4c = list.data[0]->field4c;
    int f50 = list.data[0]->field50;
    self->field50 = f50;
    self->field54 = list.data[0]->field54;
    self->field60 = list.data[0]->field60;
    self->field68 = list.data[0]->field68;
    self->field6c = list.data[0]->field6c;
    self->field58 = count;
    self->field5c = ro[1];
    self->field40 = list.data[0]->field40;
    self->x = ro[3];
    self->y = ro[12];
    self->z = ro[35];
    self->field44 = 0;
    self->field48 = list.data[0]->field48;

    char* entry = (char*)lbl_20_bss_8 + f50 * 0x18;
    entry += count * 4;
    self->model = *(void**)(entry + 0x3b0);
    self->anim = *(void**)(entry + 0x448);

    setFrame__16gfModelAnimationFd(self->anim, ro[1]);
    setUpdateRate__16gfModelAnimationFf(self->anim, ro[2]);
    g_gfSceneRoot->add(gfSceneRoot::Layer_Ground, (nw4r::g3d::ScnMdl*)self->model);

    ((Matrix*)mtx)->setIdentity();
    fn_8003F074((Matrix*)mtx, self->x, self->y, self->z);
    fn_801AAF04(self->model, 0, (Matrix*)mtx);
    fn_801AF9F4(self->model);

    freeItems(list);
}
