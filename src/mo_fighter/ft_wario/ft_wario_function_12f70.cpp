#pragma force_active on
struct WarioSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};

extern "C" {
void fn_110_6D2C(void*, int);
extern unsigned char lbl_110_data_7198[];
}

extern "C" WarioSupport* fn_110_12F70(WarioSupport* object, int nullable) {
    fn_110_6D2C(object, nullable);
    object->enabled = nullable == 0;
    object->state = 0;
    object->vtable = lbl_110_data_7198;
    return object;
}
