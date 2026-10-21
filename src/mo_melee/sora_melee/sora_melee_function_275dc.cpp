#pragma force_active on
extern float lbl_27_rodata_3CC;
extern float lbl_27_rodata_3C0;

struct Data {
    char padding[0x54];
    int value;
};

struct Result {
    void* unused;
    Data* data;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    char padding[0x28];
    Interface* interface;
};

extern "C" float fn_27_275DC(Object self) {
    if ((self.interface->get()->data->value >> 24) == 0) {
        return lbl_27_rodata_3CC;
    }
    return lbl_27_rodata_3C0;
}
