#pragma force_active on
class grYakumono;

extern "C" {
void __dl__FPv(void* p);
void __dt__10grYakumonoFv(void* p, int flag);

grYakumono* fn_40_35B90(grYakumono* self, int flag) {
    if (self) {
        __dt__10grYakumonoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
