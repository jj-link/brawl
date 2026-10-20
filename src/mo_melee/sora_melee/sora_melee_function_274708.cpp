#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* __dt__17grGimmickCatapultFv(void* self, int flag) {
    if (self) {
        __dt__10grYakumonoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
