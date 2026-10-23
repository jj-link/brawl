#pragma force_active on
extern "C" {
void __ct__14Class_802B193CFiii(void* self);
extern char lbl_80486B68[];

void* __ct__14Class_802AF338Fiii(void* self) {
    __ct__14Class_802B193CFiii(self);
    *(int*)((char*)self + 0x30) = 0;
    *(char**)self = lbl_80486B68;
    return self;
}
}
