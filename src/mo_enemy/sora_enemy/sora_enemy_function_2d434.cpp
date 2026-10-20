#pragma force_active on
#define SLOT(n) virtual void reserved##n();
#define TEN(p) \
    SLOT(p##0) SLOT(p##1) SLOT(p##2) SLOT(p##3) SLOT(p##4) \
    SLOT(p##5) SLOT(p##6) SLOT(p##7) SLOT(p##8) SLOT(p##9)

class DispatchObject {
    unsigned char padding[0x3C];

public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    TEN(1) TEN(2) TEN(3) TEN(4) TEN(5)
    TEN(6) TEN(7) TEN(8) TEN(9) TEN(10)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    virtual int invoke();
};

#undef TEN
#undef SLOT

struct Wrapper {
    unsigned char padding[0x1C];
    unsigned char* object;
};

extern "C" int fn_41_2D434(Wrapper* self) {
    unsigned char* object = self->object;
    if (object) {
        return reinterpret_cast<DispatchObject*>(object + 0xC)->invoke();
    }
    return 0;
}
