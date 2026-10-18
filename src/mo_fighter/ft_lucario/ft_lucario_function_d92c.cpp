#pragma force_active on
struct Target {
    virtual ~Target();
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void call(bool, bool) = 0;
};
struct Inner { unsigned char prefix[0x3C]; Target* target; };
struct Outer { unsigned char prefix[0xD8]; Inner* inner; };
extern "C" void fn_118_D92C(void*, Outer* object) {
    bool zero = false;
    object->inner->target->call(zero, zero);
}