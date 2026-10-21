#pragma force_active on
struct Entry {
    int key;
    int value;
};

struct Mod {
    virtual unsigned int slot0();
    virtual int* slot1(int key);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
};

extern "C" Mod* fn_101_B554(void* a);

extern "C" void fn_101_B590(void* a, void* b, Entry* table) {
    Mod* mod = fn_101_B554(a);
    if (mod->slot0() != 1 && table != 0) {
        for (int i = 0;; i++) {
            if (i >= mod->slot13()) {
                break;
            }
            Entry* e = &table[i];
            int key = e->key;
            if (key < 0) {
                break;
            }
            int value = e->value;
            *mod->slot1(key) = value;
        }
    }
}
