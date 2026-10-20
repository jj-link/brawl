#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_3DDF0[];
extern unsigned char lbl_27_data_3DED8[];
}

class soKineticEnergy;

template <class T>
class soInstanceUnitFullProperty {
public:
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();

private:
    void* vtable;
    T value;
    unsigned int state;
};

struct KineticHeader {
    void* table0;
    unsigned char flag;
    unsigned char padding[3];
    void* table8;
    void* tableC;
    void* table10;
    void* table14;
    unsigned int state;

    KineticHeader() {
        flag = 0;
        table8 = lbl_27_data_3DDF0 + 0x34;
        table0 = lbl_27_data_3DDF0;
        tableC = lbl_27_data_3DDF0 + 0x40;
        table10 = lbl_27_data_3DED8;
        table14 = lbl_27_data_3DED8 + 0x48;
        state &= 0xFFFF;
    }
};

struct KineticObject {
    KineticHeader header;
    soInstanceUnitFullProperty<soKineticEnergy*> energies[12];
    unsigned char flag;

    KineticObject(unsigned char value) : flag(value) {}
};

extern "C" void* fn_27_1ACD80(KineticObject* self, unsigned char flag) {
    self->__ct(flag);
    return self;
}
