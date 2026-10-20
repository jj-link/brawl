#pragma force_active on
class soKineticEnergy;

template<class T>
class soInstanceUnitFullProperty {
public:
    unsigned int data[3];
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();
};

inline void* operator new(unsigned long, void* p) {
    return p;
}

struct ElementArray {
    soInstanceUnitFullProperty<soKineticEnergy*> elements[8];
};

extern "C" {
extern unsigned char lbl_27_data_3E840[];
extern unsigned char lbl_27_data_3E928[];
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

struct InstanceManager {
    void* vtable;
    unsigned char nullFlag;
    unsigned char padding[3];
    void* priorityVtable;
    void* attributeVtable;
    void* arrayVtable;
    void* arrayBaseVtable;
    unsigned int flags;
    unsigned char elements[96];
    unsigned char enabled;
};

extern "C" void* fn_27_1AEB6C(InstanceManager* self, int enabled) {
    self->nullFlag = 0;
    self->priorityVtable = lbl_27_data_3E840 + 0x34;
    self->vtable = lbl_27_data_3E840;
    self->attributeVtable = lbl_27_data_3E840 + 0x40;
    self->arrayVtable = lbl_27_data_3E928;
    self->arrayBaseVtable = lbl_27_data_3E928 + 0x48;
    self->flags &= 0xFFFF;
    ((ElementArray*)self->elements)->__ct();
    self->enabled = enabled;
    return self;
}
