#pragma force_active on
class soKineticEnergy;

template <class T>
class soInstanceUnitFullProperty {
public:
    unsigned int data[3];
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();
};

extern "C" {
extern unsigned char lbl_27_data_32DB8[];
extern unsigned char lbl_27_data_36FC0[];
}

struct ElementArray {
    soInstanceUnitFullProperty<soKineticEnergy*> elements[2];
};

struct Object {
    void* v0;
    unsigned char flag4;
    unsigned char pad[3];
    void* v8;
    void* vc;
    void* v10;
    void* v14;
    unsigned long flags;
    unsigned char units[24];
    unsigned char flag34;
};

extern "C" Object* fn_27_1AD79C(Object* self, unsigned char x) {
    self->flag4 = 0;
    self->v8 = lbl_27_data_32DB8 + 0x34;
    self->v0 = lbl_27_data_32DB8;
    self->vc = lbl_27_data_32DB8 + 0x40;
    self->v10 = lbl_27_data_36FC0;
    self->v14 = lbl_27_data_36FC0 + 0x48;
    self->flags &= 0x003fffff;
    ((ElementArray*)self->units)->__ct();
    self->flag34 = x;
    return self;
}
