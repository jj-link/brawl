#pragma force_active on
extern "C" {
void fn_80193E88(void*, void*, void*);
void fn_801EC158(void*);

void fn_80195378(unsigned char* self, unsigned char*, unsigned char* arg2) {
    fn_80193E88(self + 4, arg2, arg2 + 8);
    fn_801EC158(self + 0x1C);
}
}
