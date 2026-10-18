#pragma force_active on
// Virtual slot table: slot02 sits at vtable offset 0x10 in the original.
class MarioSlotTable {
public:
    virtual void slot00(); virtual void slot01();
    virtual void* slot02();
};
extern "C" void* fn_91_BD5C(unsigned char* base) {
    MarioSlotTable* obj = reinterpret_cast<MarioSlotTable*>(base + 0x2D634);
    return obj->slot02();
}
