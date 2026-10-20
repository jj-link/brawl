#pragma force_active on
extern "C" void __dt__8clTargetFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int),
                              unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

class soCollisionAttackPart {
    unsigned char data[0x88];

public:
    ~soCollisionAttackPart();
};

soCollisionAttackPart::~soCollisionAttackPart() {
    if (data + 0x44) {
        __destroy_arr(data + 0x50, __dt__8clTargetFv, 8, 7);
    }
}
