#pragma force_active on
void* fn_803F602C(void* d, const void* s, unsigned n);

typedef struct {
    int count;
    int pad4;
    int size;
    int pad0c;
    int pad10;
    char* data;
} Vec;

static inline char* at(Vec* v, int i) {
    if (i < 0 || i >= v->count) return 0;
    return v->data + v->size * i;
}

void fn_8035A86C(Vec* v, int i) {
    int last = v->count - 1;
    if (i < last) {
        fn_803F602C(at(v, i), at(v, i + 1), v->size * (last - i));
    }
    v->count = v->count - 1;
}
