#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);

void* fn_61_3048(void* self, int size) {
    if (self) {
        __dt__Q28StSeUtil5SeSeqFv(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
