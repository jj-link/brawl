#pragma force_active on
extern "C" {
void* fn_92_AC68(void* object, int index);
void* fn_92_AC20(void* pool, int index);
int fn_27_8D3E4(void* p);

void fn_92_AB00(void* p) {
    unsigned char* obj = static_cast<unsigned char*>(p);
    int i;
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_92_AC68(obj + 0x7f60, i)) + 0x88) == 0) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_92_AC20(obj + 0xc, i)) + 0x88) == 0) {
            return;
        }
    }
}
}
