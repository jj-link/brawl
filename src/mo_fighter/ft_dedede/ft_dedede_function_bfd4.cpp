class Weapon;

extern "C" {
Weapon& fn_117_C380(void*, int);
Weapon& fn_117_C368(void*, int);
Weapon& fn_117_C350(void*, int);
Weapon* fn_117_C308(void*, int);
Weapon& fn_117_C194(void*, int);
int fn_27_8D3E4(void*);
}

// Visit article banks in order, stopping at the first failed controller call.
extern "C" void fn_117_BFD4(char* pool) {
    for (int index = 0; index < 2; ++index) {
        Weapon& article = fn_117_C380(pool + 0x3b000, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(&article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        Weapon& article = fn_117_C368(pool + 0x392b0, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(&article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        Weapon& article = fn_117_C350(pool + 0x372ec, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(&article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 4; ++index) {
        Weapon* article = fn_117_C308(pool + 0x2f3e8, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 19; ++index) {
        Weapon& article = fn_117_C194(pool + 0xc, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(&article) + 0x88) == 0) return;
    }
}
