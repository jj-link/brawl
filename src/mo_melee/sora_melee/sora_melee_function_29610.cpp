#include <math.h>
#pragma force_active on

struct Resource {
    unsigned int unused;
    void* data;
};

struct Interface {
    virtual ~Interface();
    virtual Resource* get();
};

struct Object {
    unsigned char padding[0x28];
    Interface* resource;
};

struct Matrix {
    float values[12];
};

extern "C" void fn_801341D8(void*, Matrix*);

extern "C" float fn_27_29610(const Object& self) {
    Matrix matrix;
    fn_801341D8(self.resource->get()->data, &matrix);

    float result[1];
    result[0] = fabs(matrix.values[8] - matrix.values[6]);
    return result[0];
}
