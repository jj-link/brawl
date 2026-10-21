#pragma force_active on
extern "C" void* fn_116_BD58(void* object, int index);
extern "C" void* fn_116_BD30(void* object, int index);
extern "C" void* fn_116_BCE8(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_116_BB94(void* object) {
    for (int i = 0; i < 5; ++i) {
        void* member = fn_116_BD58(static_cast<char*>(object) + 0x8D8C, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_116_BD30(static_cast<char*>(object) + 0x5BA0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        void* member = fn_116_BCE8(static_cast<char*>(object) + 0xC, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
