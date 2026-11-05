#pragma force_active on
extern void* fn_803F602C(void*, const void*, unsigned int);

typedef struct {
    int count;
    int pad4;
    int size;
    int pad0c;
    void (*destroy)(void*);
    char* data;
} Vec;

static inline char* at(Vec* v, int i) {
    if (i < 0 || i >= v->count) return 0;
    return v->data + v->size * i;
}

void fn_8035A918(Vec* v, int i) {
    int last;
    if (v->destroy) {
        v->destroy(at(v, i));
    }
    last = v->count - 1;
    if (i < last) {
        fn_803F602C(at(v, i), at(v, i + 1), v->size * (last - i));
    }
    v->count = v->count - 1;
}
