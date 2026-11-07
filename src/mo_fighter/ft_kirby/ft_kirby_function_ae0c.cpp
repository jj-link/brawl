#pragma force_active on
extern "C" {
extern char lbl_96_data_120[];
void fn_96_1D734(void*, char*);
void* fn_96_1C44C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_96_AD6C(void*, short);
}

extern "C" void* fn_96_AE0C(void* object, short deleting) {
    if (object != 0) {
        char* obj = static_cast<char*>(object);
        char* data = lbl_96_data_120;
        *reinterpret_cast<char**>(obj + 0x3C) = data;
        *reinterpret_cast<char**>(obj + 0x40) = data + 0x64;
        *reinterpret_cast<char**>(obj + 0x48) = data + 0x70;
        *reinterpret_cast<char**>(obj + 0x54) = data + 0x84;
        *reinterpret_cast<char**>(obj + 0x64) = data + 0xDC;
        *reinterpret_cast<char**>(obj + 0x70) = data + 0xEC;
        *reinterpret_cast<char**>(obj + 0x7C) = data + 0xFC;
        *reinterpret_cast<char**>(obj + 0x88) = data + 0x110;
        *reinterpret_cast<char**>(obj + 0x94) = data + 0x128;
        *reinterpret_cast<char**>(obj + 0xA0) = data + 0x140;
        *reinterpret_cast<char**>(obj + 0xAC) = data + 0x158;
        *reinterpret_cast<char**>(obj + 0xB8) = data + 0x16C;
        *reinterpret_cast<char**>(obj + 0xC4) = data + 0x180;
        *reinterpret_cast<char**>(obj + 0xD0) = data + 0x190;
        *reinterpret_cast<char**>(obj + 0xDC) = data + 0x1C4;
        *reinterpret_cast<char**>(obj + 0xE8) = data + 0x1D4;
        *reinterpret_cast<char**>(obj + 0xF4) = data + 0x1E8;
        *reinterpret_cast<char**>(obj + 0x100) = data + 0x254;
        short minus1 = -1;
        fn_96_1D734(obj + 0x1B72C, data);
        fn_96_1C44C(obj + 0x1B72C, minus1);
        fn_27_C74E8(obj + 0x1B67C, minus1);
        fn_96_AD6C(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
