#pragma force_active on
#pragma exceptions off

class soKineticEnergy;

template<class T>
class soInstanceUnitFullProperty {
public:
    unsigned int data[3];
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();
};

struct ElementArray {
    soInstanceUnitFullProperty<soKineticEnergy*> elements[2];
};

extern "C" {
void fn_27_1DBE08(void*, void*, void*, void*);
extern unsigned char lbl_27_data_32DB8[];
extern unsigned char lbl_27_data_36FC0[];
extern unsigned char lbl_27_data_9E58[];
}

struct SoUnit {
    unsigned char pad0[0x30];
    void* vtable;
    unsigned char nullFlag;
    unsigned char pad1[3];
    void* priorityVtable;
    void* attributeVtable;
    void* arrayVtable;
    void* arrayBaseVtable;
    unsigned int flags;
    unsigned char elements[24];
    unsigned char enabled;
    unsigned char pad2[3];
    void* fieldB0;
};

extern "C" SoUnit* fn_27_1E3968(SoUnit* self, void* article) {
    fn_27_1DBE08(self, article, &self->vtable, &self->fieldB0);
    const unsigned char* base = lbl_27_data_32DB8;
    self->nullFlag = 0;
    self->vtable = (void*)base;
    self->priorityVtable = (void*)(base + 0x34);
    self->attributeVtable = (void*)(base + 0x40);
    self->arrayVtable = (void*)lbl_27_data_36FC0;
    self->arrayBaseVtable = (void*)(lbl_27_data_36FC0 + 0x48);
    self->flags &= 0x3FFFFF;
    ((ElementArray*)self->elements)->__ct();
    self->enabled = 0;
    self->fieldB0 = (void*)lbl_27_data_9E58;
    return self;
}
