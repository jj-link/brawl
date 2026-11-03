#pragma force_active on
extern "C" float randf__Fv();

struct Foo {
    unsigned char pad[0x9C];
    void* field_9C;
    unsigned char pad2[0x1F6];
    unsigned char field_296;
};

extern "C" void fn_71_2068(Foo* self) {
    void* ptr = self->field_9C;
    self->field_296 = 3;
    if (ptr != 0) {
        float* f = (float*)ptr;
        float sum = f[0] + f[1] + f[2] + f[3];
        float d3 = f[3] / sum;
        float d2 = f[2] / sum;
        float d1 = f[1] / sum;
        float r = randf__Fv();
        if (r < d3) {
            self->field_296 = 3;
        } else if (r < d3 + d2) {
            self->field_296 = 4;
        } else if (r < d3 + d2 + d1) {
            self->field_296 = 5;
        } else {
            self->field_296 = 6;
        }
    }
}