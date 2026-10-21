#pragma force_active on
extern "C" {

void fn_80109540(int arg);

struct _S {
    int pad[37]; // 37 * 4 = 148 = 0x94
    int m;
};

void fn_800DCF04(_S* self) {
    if (self->m)
        fn_80109540(self->m);
}

}
