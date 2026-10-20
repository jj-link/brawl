#pragma force_active on
extern "C" {
int fn_27_8D3E4(void*);
void* fn_109_A3DC(void* object, int index);
void* fn_109_A3C4(void* object, int index);
}

extern "C" void fn_109_A2A8(void* p) {
    for (int i = 0; i < 1; i++) {
        void* m = fn_109_A3DC(static_cast<unsigned char*>(p) + 0x16e0, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(m) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; i++) {
        void* m = fn_109_A3C4(static_cast<unsigned char*>(p) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(m) + 0x88) == 0) {
            break;
        }
    }
}
