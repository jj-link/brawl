#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
typedef struct {
    void* data;
    int size;
    unsigned int capacity;
} Array;
extern void* lbl_805A0EC8;
extern void* fn_8027EA20(void*, unsigned int, int);
extern void fn_8027EABC(void*, void*, unsigned int, int);
extern void fn_80281BBC(void*, void*, int);
void fn_8027CEF4(Array* self, int stride, void* data, int capacity) {
    int n;
    int flag;
    void* p;
    if (data != 0 && self->size < capacity) {
        p = data;
        n = capacity;
        flag = 0x80000000;
    } else {
        n = (int)(self->capacity & 0x3fffffff) / 2;
        p = fn_8027EA20(lbl_805A0EC8, n * stride, 0x15);
        flag = 0;
    }
    fn_80281BBC(p, self->data, self->size * stride);
    fn_8027EABC(lbl_805A0EC8, self->data, stride * (self->capacity & 0x3fffffff), 0x15);
    self->data = p;
    self->capacity = (self->capacity & 0x40000000) | (n | flag);
}