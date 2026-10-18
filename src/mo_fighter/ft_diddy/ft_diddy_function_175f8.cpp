#pragma force_active on
extern "C" {
void fn_115_6654(void*, bool);
extern unsigned char lbl_115_data_8464[];
}

struct Object {
    void* vtable;
    unsigned char pad4;
    unsigned char flags : 1;
    unsigned char reserved : 7;
    unsigned char state;
};

extern "C" Object* fn_115_175F8(Object* object, bool enabled) {
    fn_115_6654(object, enabled);
    object->flags = enabled == false;
    object->state = 0;
    object->vtable = lbl_115_data_8464;
    return object;
}
