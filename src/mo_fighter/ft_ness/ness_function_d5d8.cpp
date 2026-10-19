#pragma force_active on
struct NessWorkPointers { void* a; void* b; void* c; };
struct NessWorkArrays;
struct NessWorkCache { void* head; NessWorkPointers cached; };

extern "C" NessWorkPointers fn_101_D62C(NessWorkArrays* work, int index);

extern "C" NessWorkPointers* fn_101_D5D8(NessWorkCache* self, int index) {
    self->cached = fn_101_D62C(reinterpret_cast<NessWorkArrays*>(self), index);
    return &self->cached;
}
