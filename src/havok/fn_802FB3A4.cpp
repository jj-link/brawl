#pragma force_active on
extern "C" void fn_802A1E8C(void* self, int index);

extern "C" void fn_802FB3A4(unsigned char* self, unsigned char* obj, unsigned int key) {
    int i;
    unsigned char* p;
    int n = obj[0x21];
    p = obj;
    for (i = 0; i < n; i++) {
        if (key == *(unsigned short*)(p + 2)) {
            fn_802A1E8C(obj, i);
            self[2]--;
            return;
        }
        p += 4;
    }
}
