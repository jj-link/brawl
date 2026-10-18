#pragma force_active on
extern "C" void* fn_94_19AF4(char* object, int index);
extern "C" void* fn_94_19ACC(void* object, int index);
extern "C" void* fn_94_19AB4(void* object, int index);
extern "C" void* fn_94_19A24(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_94_198DC(void* object) {
    for (int i = 0; i < 1; ++i) {
        void* member = fn_94_19AF4(static_cast<char*>(object) + 0xfc38, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_94_19ACC(static_cast<char*>(object) + 0xcc4c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_94_19AB4(static_cast<char*>(object) + 0xaef0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 8; ++i) {
        void* member = fn_94_19A24(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
