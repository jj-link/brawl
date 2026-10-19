#pragma force_active on
struct Fn78Entry {
    char pad[8];
    int flag;
};

extern "C" char* fn_78_571C(Fn78Entry* self, int index) {
    int sh = self->flag >> 30;
    int n = sh + index;
    if (n >= 1) {
        n = n - 1;
    }
    return (char*)self + 0xc + n * 0x78;
}
