#pragma force_active on
extern "C" {
void* fn_123_B5EC(void*, int);
void* fn_123_B5D4(void*, int);
int fn_27_8D3E4(void*);

void fn_123_B4B8(void* object) {
    unsigned char* p = static_cast<unsigned char*>(object);
    for (int i = 0; i < 1; ++i) {
        void* member = fn_123_B5EC(p + 0x2d48, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_123_B5D4(p + 0xc, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
}
