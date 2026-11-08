#pragma force_active on
extern const float lbl_61_rodata_54;

class Class_2AF8 {
public:
    virtual void fn_61_BFE0();
    virtual void fn_61_B400();
    virtual void fn_61_B410();
    virtual void fn_61_A744();
    virtual void fn_61_A438();
    virtual void fn_61_9C8C();
    virtual float fn_61_B73C();
};

class Class_3B48 {
public:
    virtual void fn_61_BFE0();
    virtual void fn_61_B400();
    virtual void fn_61_B410();
    virtual void fn_61_E788();
    virtual void fn_61_A438();
    virtual void fn_61_E6A0();
    virtual float fn_61_B73C();
};

struct FZeroEntry {
    unsigned char reserved[0xc];
    Class_2AF8* object;
};

struct FZeroStage {
    unsigned char reserved[0x48];
    FZeroEntry** entries;
};

extern "C" float fn_61_5CC4(FZeroStage* stage, int index) {
    FZeroEntry* entry = stage->entries[index];
    if (entry == 0) {
        return lbl_61_rodata_54;
    }
    return entry->object->fn_61_B73C();
}
