#pragma force_active on
typedef int (*VFn)(void*, int);

int fn_80204E6C(void* self, int arg) {
    VFn* vtbl = *(VFn**)self;
    return vtbl[1](self, arg);
}
