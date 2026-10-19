#pragma force_active on
class soCollisionAttackPart {
public:
    ~soCollisionAttackPart();
    unsigned char data[0x90];
};

class soCollisionAttackOwner {
public:
    unsigned char pad[0xc];
    soCollisionAttackPart part[1];
};

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);

soCollisionAttackOwner* fn_56_5900(soCollisionAttackOwner* self, int flags) {
    if (self) {
        __destroy_arr(self->part, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
