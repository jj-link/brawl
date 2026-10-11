struct NessEnabledSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};
struct NessLinkedSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char padding[3];
    void* linkedObject;
    int index;
};

extern "C" {
void* fn_101_9210(void*, int);
extern unsigned char lbl_101_data_9848[], lbl_101_data_96F8[];
}

extern "C" NessEnabledSupport* fn_101_15664(NessEnabledSupport* object, int nullable) {
    fn_101_9210(object, nullable);
    object->enabled = nullable == 0;
    object->state = 0;
    object->vtable = lbl_101_data_9848;
    return object;
}

extern "C" NessLinkedSupport* fn_101_156C4(NessLinkedSupport* object, void* linkedObject) {
    fn_101_9210(object, 0);
    object->vtable = lbl_101_data_96F8;
    object->linkedObject = linkedObject;
    object->index = -1;
    return object;
}
