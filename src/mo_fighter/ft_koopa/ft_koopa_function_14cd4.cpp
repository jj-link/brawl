#pragma force_active on
extern "C" {
void* fn_102_14D80(void*, int);
int fn_27_8D3E4(void*);

void fn_102_14CD4(void* object) {
    for (int index = 0; index < 6; ++index) {
        void* member = fn_102_14D80(static_cast<unsigned char*>(object) + 0x0C, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
}
