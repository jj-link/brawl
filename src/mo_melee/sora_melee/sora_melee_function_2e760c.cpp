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

struct PropertyArray {
    soInstanceUnitFullProperty<soKineticEnergy*> entries[3];
};

struct Obj {
    char pad[0x30];
    unsigned char* p30;
    unsigned char b34;
    char pad_35[3];
    unsigned char* p38;
    unsigned char* p3c;
    unsigned char* p40;
    unsigned char* p44;
    unsigned int f48;
    PropertyArray arr;
    unsigned char b70;
    char pad_71[3];
    unsigned char* p74;
};

extern "C" {
extern unsigned char lbl_27_data_7D7A0[];
extern unsigned char lbl_27_data_7D888[];
extern unsigned char lbl_27_data_9E58[];
void fn_27_1DBE08(void*, void*, void*, void*);
}

extern "C" Obj* fn_27_2E760C(Obj* self, void* arg1) {
    fn_27_1DBE08(self, arg1, &self->p30, &self->p74);
    self->b34 = 0;
    unsigned char* base = lbl_27_data_7D7A0;
    self->p30 = base;
    self->p38 = base + 0x34;
    self->p3c = base + 0x40;
    self->p40 = lbl_27_data_7D888;
    self->p44 = lbl_27_data_7D888 + 0x48;
    self->f48 &= 0x3FFFFF;
    self->arr.__ct();
    self->b70 = 0;
    self->p74 = lbl_27_data_9E58;
    return self;
}
