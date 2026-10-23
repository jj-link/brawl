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
    soInstanceUnitFullProperty<soKineticEnergy*> elements[8];
};

extern "C" {
void fn_27_1DBE08(void*, void*, void*, void*);
extern unsigned char lbl_27_data_3E840[];
extern unsigned char lbl_27_data_3E928[];
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
    unsigned char elements[96];
    unsigned char enabled;
    unsigned char pad2[3];
    void* fieldB0;
};

extern "C" SoUnit* fn_27_2DB55C(SoUnit* self, void* article) {
    fn_27_1DBE08(self, article, &self->vtable, &self->fieldB0);
    unsigned char* const base = lbl_27_data_3E840;
    self->nullFlag = 0;
    self->vtable = base;
    self->priorityVtable = base + 0x34;
    self->attributeVtable = base + 0x40;
    self->arrayVtable = lbl_27_data_3E928;
    self->arrayBaseVtable = lbl_27_data_3E928 + 0x48;
    self->flags &= 0xFFFF;
    ((ElementArray*)self->elements)->__ct();
    self->enabled = 0;
    self->fieldB0 = (void*)lbl_27_data_9E58;
    return self;
}
