#pragma force_active on
#pragma scheduling off

struct Matrix {
    unsigned int words[12];
};

struct Target {
    unsigned char padding[0x50];
    Matrix matrix;
};

struct Object {
    unsigned char padding[0xD4];
    Target* target;
};

extern "C" void fn_27_26DD40(Object* object, const Matrix* matrix) {
    Target* target = object->target;
    if (target) {
        target->matrix = *matrix;
    }
}
