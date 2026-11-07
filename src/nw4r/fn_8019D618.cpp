#pragma force_active on

extern "C" unsigned int fn_80196B1C(void*);
extern "C" unsigned int fn_80196CD0(void*);
extern "C" unsigned int fn_80196DFC(void*);
extern "C" unsigned int fn_80196FD4(void*);
extern "C" void* fn_80196A70(void*, unsigned int);
extern "C" void* fn_80196C24(void*, unsigned int);
extern "C" void* fn_80196D50(void*, unsigned int);
extern "C" void* fn_80196F28(void*, unsigned int);
extern "C" void fn_80195F08(void**, void*, float);
extern "C" void fn_80195FD8(void**, void*, float);
extern "C" void fn_801963D0(void**, void*, float);
extern "C" void fn_80196530(void**, void*, float);
struct Obj {
    char pad[12];
    float value;
    char pad2[16];
    char resource[8];
    char* a;
    char* b;
    char* c;
    char* d;
};
extern "C" void fn_8019D618(Obj* self) {
    unsigned int n1 = fn_80196B1C(self->resource);
    unsigned int n2 = fn_80196CD0(self->resource);
    unsigned int n3 = fn_80196DFC(self->resource);
    unsigned int n4 = fn_80196FD4(self->resource);
    float f = self->value;
    int offset;
    unsigned int i, i2, i3, i4;
    for (i = 0, offset = 0; i < n1; offset += 8, ++i) {
        void* p = fn_80196A70(self->resource, i);
        fn_80195F08(&p, self->a + offset, f);
    }
    for (i2 = 0, offset = 0; i2 < n2; offset += 0x40, ++i2) {
        void* p = fn_80196C24(self->resource, i2);
        fn_80195FD8(&p, self->b + offset, f);
    }
    for (i3 = 0, offset = 0; i3 < n3; offset += 0x10, ++i3) {
        void* p = fn_80196D50(self->resource, i3);
        fn_801963D0(&p, self->c + offset, f);
    }
    for (i4 = 0, offset = 0; i4 < n4; offset += 0x34, ++i4) {
        void* p = fn_80196F28(self->resource, i4);
        fn_80196530(&p, self->d + offset, f);
    }
}