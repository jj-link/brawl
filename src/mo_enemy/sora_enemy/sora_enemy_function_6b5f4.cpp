#pragma force_active on
extern "C" {
void setProcFnc_TouchGround__10wnemSimpleFl(void*, long);
void setProcFnc_HitShell__10wnemSimpleFl(void*, long);
void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
void changeProcFnc__10wnemSimpleFll(void*, long, long);
}

extern "C" void fn_41_6B5F4(void* enemy) {
    unsigned char entered = *reinterpret_cast<unsigned char*>(static_cast<char*>(enemy) + 0x2214);
    *reinterpret_cast<unsigned char*>(static_cast<char*>(enemy) + 0x2214) = 0;

    if (entered) {
        setProcFnc_TouchGround__10wnemSimpleFl(enemy, 0x38);
        setProcFnc_HitShell__10wnemSimpleFl(enemy, 0x38);
    }

    executeAnimCmd__10wnemSimpleFUl(enemy, 2);

    if (*reinterpret_cast<unsigned char*>(static_cast<char*>(enemy) + 0x2218)) {
        changeProcFnc__10wnemSimpleFll(enemy, 0x38, 1);
    }
}
