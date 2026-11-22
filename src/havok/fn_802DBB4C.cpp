#pragma force_active on
extern "C" void fn_8027CE3C(void*, int);
struct Self { int* data; int count; int capacity; };
extern "C" void fn_802DBB4C(Self* self, const int* value) {
    if (self->count == (self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(self, 4);
    }
    int* dest = &self->data[self->count++];
    *dest = *value;
}
