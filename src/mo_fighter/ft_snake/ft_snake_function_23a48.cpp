#pragma force_active on
extern "C" {
void* fn_122_23AC8(void*, int);
int fn_27_8D3E4(void*);

void fn_122_23A48(void* object) {
    for (int index = 0; index < 2; ++index) {
        void* member = fn_122_23AC8(static_cast<unsigned char*>(object) + 0xC, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
}
