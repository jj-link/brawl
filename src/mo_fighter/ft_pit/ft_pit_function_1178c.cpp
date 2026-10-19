#pragma force_active on
struct PitEnabledSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};

extern "C" {
void fn_112_7674(void*, int);
extern unsigned char lbl_112_data_75E0[];
}

extern "C" PitEnabledSupport* fn_112_1178C(PitEnabledSupport* object, int nullable) {
    fn_112_7674(object, nullable);
    object->enabled = nullable == 0;
    object->state = 0;
    object->vtable = lbl_112_data_75E0;
    return object;
}
