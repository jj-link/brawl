#pragma force_active on
typedef void (*VFn)(void*, int);

void fn_80204E5C(void* p, int a) {
    (*(VFn*)(*(int*)p))(p, a);
}
