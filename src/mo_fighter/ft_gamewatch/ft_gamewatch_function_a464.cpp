#pragma force_active on
extern "C" {
void fn_27_19A91C(void*, int, int);
void fn_27_10158(void*, void*, unsigned int, void*, int);

void* fn_107_A464(void* self, void* arg2, unsigned int arg3) {
    fn_27_19A91C(self, 2, 0);
    fn_27_10158((char*)self + 0x7C, arg2, arg3, self, 1);
    return self;
}
}
