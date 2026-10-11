// ABI-local view of the mantle fields used by its leaf callbacks.
struct MarioMantleFlags {
    unsigned char reserved : 1;
    unsigned char enabled : 1;
};
struct MarioMantleLeafFields {
    unsigned char prefix[0x28];
    void* owner;
    unsigned char beforeVtable[0x10];
};
struct MarioMantleLeaf : MarioMantleLeafFields {
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07(); virtual void slot08();
    virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19(); virtual void slot20();
    virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26();
    virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32();
    virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38();
    virtual void slot39(); virtual void slot40();
    virtual void dispatch();
    unsigned char beforeFlags[0x64];
    MarioMantleFlags flags;
    unsigned char beforeResource[0x1b];
    void* resource;
};
extern "C" void* fn_91_FF8C(MarioMantleLeaf* mantle) { return mantle->resource; }
extern "C" void* fn_91_FF94(MarioMantleLeaf* mantle) { return mantle->owner; }
extern "C" void fn_91_FF9C(MarioMantleLeaf* mantle) {
    mantle->dispatch();
}
extern "C" bool fn_91_FFAC(MarioMantleLeaf* mantle) { return mantle->flags.enabled != 0; }
extern "C" void fn_91_FFC0(MarioMantleLeaf* mantle, bool enabled) { mantle->flags.enabled = enabled; }
extern "C" bool fn_91_FFD0(MarioMantleLeaf*, signed char kind) { return kind == static_cast<signed char>(12); }
extern "C" bool fn_91_FFEC(MarioMantleLeaf*) { return false; }
extern "C" bool fn_91_FFF4(MarioMantleLeaf*) { return true; }
