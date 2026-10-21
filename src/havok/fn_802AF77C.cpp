#pragma force_active on
extern "C" {
void fn_802B1B08(void *self);
void fn_802FC988(void *self);

void fn_802AF77C(char *self)
{
    if (*(signed char *)(self + 0x78) != 0) {
        return fn_802B1B08(self);
    }
    return fn_802FC988(self + 0x30);
}
}
