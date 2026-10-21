#pragma force_active on
extern "C" void fn_8019DA5C(void* self, unsigned int mask, int flag);

extern "C" void fn_80197638(int* self, int key, int unused, int val) {
    switch (key) {
    case 8:
        fn_8019DA5C(self, 2, 1);
        break;
    case 0x10003:
        self[1] = 0;
        break;
    case 0x10002:
        self[1] = val;
        break;
    }
}
