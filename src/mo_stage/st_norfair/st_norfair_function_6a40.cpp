#pragma force_active on
#include <so/so_array.h>

struct Element {
    float m0;
    float m4;
    float m8;
    float mc;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1c;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned short m2c;
    unsigned short m2e;
    unsigned char m30;
    unsigned char m31;
    unsigned char m32;
    unsigned char m33;
    unsigned char m34;
    unsigned char m35;
    unsigned char m36;
    unsigned char m37;
    unsigned char m38;
    unsigned char m39;
    unsigned char m3a;
    unsigned int m3c;
    unsigned int m40;
    unsigned int m44;
    unsigned int m48;
    float m4c;
    unsigned int m50;
    unsigned int m54;
    unsigned int m58;
    unsigned int m5c;
    float m60;
    float m64;
    float m68;
    unsigned int m6c;
    unsigned int m70;
    unsigned int m74;
    unsigned int m78;
    float m7c;
    unsigned int m80;
    unsigned int m84;
    unsigned int m88;
    unsigned int m8c;
    unsigned int m90;
    float m94;
    unsigned int m98;
    unsigned char m9c;
};

extern "C" void fn_54_6A40(soArrayVectorAbstract<Element>* self, const Element* value) {
    s32 pos = soArrayVectorCalculator::unshift(
        *self, self->isFull(), self->capacity(),
        self->getTopIndex(), self->getLastIndex());
    Element* d = &self->getArrayValueConst(pos);

    d->m0 = value->m0;
    d->m4 = value->m4;
    d->m8 = value->m8;
    d->mc = value->mc;
    d->m10 = value->m10;
    d->m14 = value->m14;
    d->m18 = value->m18;
    d->m1c = value->m1c;
    d->m20 = value->m20;
    d->m24 = value->m24;
    d->m28 = value->m28;
    d->m2c = value->m2c;
    d->m2e = value->m2e;
    d->m30 = value->m30;
    d->m31 = value->m31;
    d->m32 = value->m32;
    d->m33 = value->m33;
    d->m34 = value->m34;
    d->m35 = value->m35;
    d->m36 = value->m36;
    d->m37 = value->m37;
    d->m38 = value->m38;
    d->m39 = value->m39;
    d->m3a = value->m3a;
    d->m3c = value->m3c;
    d->m40 = value->m40;
    d->m44 = value->m44;
    d->m48 = value->m48;
    d->m4c = value->m4c;
    d->m50 = value->m50;
    d->m54 = value->m54;
    d->m58 = value->m58;
    d->m5c = value->m5c;
    d->m60 = value->m60;
    d->m64 = value->m64;
    d->m68 = value->m68;
    d->m6c = value->m6c;
    d->m70 = value->m70;
    d->m74 = value->m74;
    d->m78 = value->m78;
    d->m7c = value->m7c;
    unsigned int w84 = value->m84;
    d->m80 = value->m80;
    unsigned int w88 = value->m88;
    d->m84 = w84;
    d->m88 = w88;
    d->m8c = value->m8c;
    d->m90 = value->m90;
    d->m94 = value->m94;
    d->m98 = value->m98;
    d->m9c = value->m9c;

    self->setSize(self->size() + 1);
}
