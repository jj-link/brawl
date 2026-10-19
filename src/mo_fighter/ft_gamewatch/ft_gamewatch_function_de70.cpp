#pragma force_active on
extern "C" void* fn_107_E11C(void* object, int index);
extern "C" void* fn_107_E104(void* object, int index);
extern "C" void* fn_107_E0EC(void* object, int index);
extern "C" void* fn_107_E0D4(void* object, int index);
extern "C" void* fn_107_E0BC(void* object, int index);
extern "C" void* fn_107_E0A4(void* object, int index);
extern "C" void* fn_107_E08C(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_107_DE70(void* object) {
    for (int i = 0; i < 5; ++i) {
        void* member = fn_107_E11C(static_cast<char*>(object) + 0xcdec, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E104(static_cast<char*>(object) + 0xad00, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E0EC(static_cast<char*>(object) + 0x8c14, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E0D4(static_cast<char*>(object) + 0x6b0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E0BC(static_cast<char*>(object) + 0x4a20, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E0A4(static_cast<char*>(object) + 0x20f8, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_107_E08C(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
