#pragma force_active on
class grYakumono;
extern "C" void setValidAttachedEffect__10grYakumonoFUl(grYakumono*, unsigned int);

extern "C" void fn_40_36A14(grYakumono* self, unsigned int effect) {
    setValidAttachedEffect__10grYakumonoFUl(self, effect);
    if (effect == 0) {
        *((unsigned char*)self + 0x150) = 5;
    } else {
        *((unsigned char*)self + 0x150) = 0;
    }
}
