#pragma force_active on
typedef unsigned char u8;

struct Elem12 {
    u8 data[12];
};

struct Container {
    u8 header[12];
    Elem12 elems[1];
};

extern "C" void* fn_27_1CFCBC(Container* self, int index)
{
    return &self->elems[index];
}
