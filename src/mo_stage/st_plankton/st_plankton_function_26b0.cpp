#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void* self, int flags);
void __dl__FPv(void* p);

void* fn_74_26B0(void* self, int flags)
{
    if (self != 0) {
        __dt__10grYakumonoFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
