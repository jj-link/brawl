#pragma force_active on
extern "C" void* fn_8027EA20(void*, unsigned int, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Entry { int a; int b; };
struct Array { Entry* data; int size; unsigned int capacity; };
inline int getCapacity(const Array* array) { return array->capacity & 0x3fffffff; }
inline int getSize(const Array* array) { return array->size; }
inline void copyArray(Array* array, int size, const Array* source) {
    Entry* dst = array->data;
    array->size = size;
    const Entry* src = source->data;
    for (int i = 0; i < size; ++i) {
        dst[i] = src[i];
    }
}
struct Object { char pad[0x30]; Array first; Array second; };

extern "C" void fn_8033213C(Object* self, Array* first, Array* second) {
    int capacity = getCapacity(first);
    if (capacity < self->first.size) {
        if (!(first->capacity & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, first->data, capacity * 8, 0x15);
        }
        first->data = (Entry*)fn_8027EA20(lbl_805A0EC8, self->first.size * 8, 0x15);
        first->capacity = self->first.size | (first->capacity & 0x40000000);
    }
    copyArray(first, self->first.size, &self->first);

    capacity = getCapacity(second);
    if (capacity < self->second.size) {
        if (!(second->capacity & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, second->data, capacity * 8, 0x15);
        }
        second->data = (Entry*)fn_8027EA20(lbl_805A0EC8, self->second.size * 8, 0x15);
        second->capacity = self->second.size | (second->capacity & 0x40000000);
    }
    copyArray(second, self->second.size, &self->second);
}
