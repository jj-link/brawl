#pragma force_active on
typedef void (*DelegateFn)(void*, void*, void*);

typedef struct Delegate {
    void* self;
    DelegateFn fn;
    void* data;
} Delegate;

void fn_80370A58(void* a, Delegate* d) {
    d->fn(d->self, a, d->data);
}
