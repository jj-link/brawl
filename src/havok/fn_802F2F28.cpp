#pragma force_active on
extern "C" {
void fn_8028564C(void);

void* fn_802F2F28(void* p) {
    fn_8028564C();
    return p;
}
}
