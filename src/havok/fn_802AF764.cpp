#pragma force_active on
extern "C" {
void fn_802B1A6C(void *self);
void fn_802FC824(void *self);

void fn_802AF764(char *self)
{
    if (*(signed char *)(self + 0x78) != 0) {
        fn_802B1A6C(self);
    } else {
        fn_802FC824(self + 0x30);
    }
}
}
