#pragma force_active on
extern "C" {
int fn_800FAB7C(void*);
void fn_800F89F4(void*);
void fn_800F92A4(void*);
void fn_800B9984(void*);
void fn_800F96AC(void*);
void fn_800FA0D0(void*);

void fn_800F9630(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (!p[0x101]) {
        if (!fn_800FAB7C(self))
            return;
        fn_800F89F4(self);
        fn_800F92A4(self);
        p[0x101] = 1;
    }
    fn_800B9984(p + 0x48);
    fn_800F96AC(self);
    if ((p[0x100] >> 7) & 1)
        fn_800FA0D0(self);
}
}