#pragma force_active on
extern "C" {
void fn_802B2A24(void* self);

void fn_802AF7A8(char* self) {
    if (self[0x78]) {
        fn_802B2A24(self);
    }
}
}
