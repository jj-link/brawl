#pragma force_active on
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
extern "C" void fn_27_262430();
extern "C" void setIdentity__6MatrixFv(void*);

extern const float lbl_27_rodata_42B8;
extern const float lbl_27_rodata_42BC;

struct Data {
    float a, b, c, d, e, f, g, h, i;
    float j, k, l, m, n, o, p, q, r;

    Data()
        : a(lbl_27_rodata_42B8),
          b(lbl_27_rodata_42B8),
          c(lbl_27_rodata_42B8),
          d(lbl_27_rodata_42B8),
          e(lbl_27_rodata_42B8),
          f(lbl_27_rodata_42B8),
          g(lbl_27_rodata_42BC),
          h(lbl_27_rodata_42BC),
          i(lbl_27_rodata_42BC),
          j(lbl_27_rodata_42B8),
          k(lbl_27_rodata_42B8),
          l(lbl_27_rodata_42B8),
          m(lbl_27_rodata_42B8),
          n(lbl_27_rodata_42B8),
          o(lbl_27_rodata_42B8),
          p(lbl_27_rodata_42BC),
          q(lbl_27_rodata_42BC),
          r(lbl_27_rodata_42BC) {}
};

struct Callback {
    int a, b;
    Data data;
    char matrix[48];
};

struct Obj {
    int pad;
    Callback* callbacks;
    unsigned long count;
};

static Callback* allocCallbacks(Obj* self, int heap)
{
    unsigned long count = self->count;
    return (Callback*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(count * 128 + 16, heap),
        fn_27_262430, 0, 128, count);
}

extern "C" int fn_27_2622AC(Obj* self, int skip, int heap)
{
    Callback* arr;
    switch (skip) {
    case 0:
        arr = allocCallbacks(self, heap);
        self->callbacks = arr;
        break;
    default:
        arr = 0;
    }
    if (arr == 0) {
        return 0;
    }
    int i = 0;
    int n = self->count;
    for (; i != n; i++) {
        Callback* cb = &self->callbacks[i];
        cb->a = 0;
        cb->b = 0;
        cb->data = Data();
        setIdentity__6MatrixFv(cb->matrix);
    }
    return 1;
}