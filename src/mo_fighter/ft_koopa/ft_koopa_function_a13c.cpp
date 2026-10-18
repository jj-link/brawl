#pragma force_active on
extern "C" {
void* fn_102_A22C(void*, int);
int fn_27_8D3E4(void*);

void fn_102_A13C(void* object) {
    for (int index = 0; index < 6; ++index) {
        void* member = fn_102_A22C(static_cast<unsigned char*>(object) + 0x0C, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) {
            break;
        }
    }
}
}
