#pragma force_active on
struct FieldWord {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 12;
};

extern "C" void fn_27_1A3498(void* self, unsigned int v) {
    FieldWord* p = (FieldWord*)((char*)self + 8);
    p->b = v;
}
