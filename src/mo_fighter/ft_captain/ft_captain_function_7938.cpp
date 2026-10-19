#pragma force_active on
extern "C" {
void fn_27_CB410(void*, int, int);
void fn_27_B215C(void*, void*, void*, void*, void*, void*);
}

extern "C" void* fn_100_7938(void* fighter, void* a, void* b, void* c, void* d) {
    fn_27_CB410(fighter, 1, 0);
    fn_27_B215C(static_cast<char*>(fighter) + 0x50, a, fighter, b, c, d);
    return fighter;
}
