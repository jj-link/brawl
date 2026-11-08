#pragma force_active on
extern "C" void fn_8027CE3C(void*, int);
struct Object {
    unsigned char pad[0x22];
    unsigned short index;
    unsigned char state24;
    unsigned char state25;
    unsigned char pad26;
    unsigned char state : 2;
    unsigned char flags : 6;
};
struct Self {
    unsigned char pad[0x40];
    void** data;
    int count;
    int capacity;
};
extern "C" void fn_802FAC88(Self* self, Object* obj) {
    obj->state = 1;
    obj->state25 = 0;
    obj->state24 = 0;
    if (obj->index == 0xFFFF) {
        obj->index = self->count;
        if (self->count == (self->capacity & 0x3FFFFFFF)) {
            fn_8027CE3C(&self->data, 4);
        }
        self->data[self->count++] = obj;
    }
}