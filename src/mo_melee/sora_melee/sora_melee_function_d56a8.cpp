#pragma force_active on
#include <so/so_instance_unit.h>

typedef unsigned char u8;
class soLinkEventObserver;
template<class T> struct soEventUnitWrapper { static u8 __vt[]; };
template<> class soInstanceUnitFullProperty<soLinkEventObserver*> {
public:
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();
    void* element;
    int id;
    soAttributeFlag attribute;
    s16 parameter;
};
class Object_vptr_0 {
public:
    virtual s16 slot0(void*);
};
extern "C" {
void* getInstance__13soEventSystemFv();
Object_vptr_0* getManager__13soEventSystemFl(void*, long);
extern u8 lbl_27_data_19B18[];
extern u8 lbl_27_data_25B70[];
extern u8 lbl_27_data_25C60[];
}
struct Elements {
    soInstanceUnitFullProperty<soLinkEventObserver*> elements[1];
    Elements() {}
};
struct Work {
    void* v0; u8 flag; u8 pad[3];
    void* v8; void* vC; void* v10; void* v14;
    unsigned long bits;
    u8 data[12];
    u8 tail;
};
struct Object {
    void* vptr; s16 manager; s16 event;
    Work* list; Work work;
};
extern "C" Object* fn_27_D56A8(Object* self, s16 m, s16 e) {
    self->manager = m;
    self->vptr = soEventUnitWrapper<soLinkEventObserver>::__vt;
    self->event = e;
    if (m != -1) {
        s16 id = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->manager)->slot0(self);
        if (id > -1) self->event = id;
    }
    Work* work = &self->work;
    self->list = work;
    self->vptr = lbl_27_data_19B18;
    work->flag = 0;
    work->v0 = lbl_27_data_25B70;
    work->v8 = lbl_27_data_25B70 + 0x34;
    work->vC = lbl_27_data_25B70 + 0x40;
    work->v10 = lbl_27_data_25C60;
    work->v14 = lbl_27_data_25C60 + 0x48;
    work->bits &= 0x01ffffff;
    reinterpret_cast<Elements*>(work->data)->__ct();
    work->tail = 0;
    return self;
}
