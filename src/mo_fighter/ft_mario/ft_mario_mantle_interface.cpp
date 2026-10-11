struct MarioMantleInterface {
    unsigned char prefix[0xb8];
    void* resource;
};
extern "C" {
extern const float lbl_91_rodata_30;
extern const float lbl_91_rodata_34;
// These interface hooks are intentionally empty in the original module.
void fn_91_10100(MarioMantleInterface*) {}
void fn_91_10104(MarioMantleInterface*) {}
void fn_91_10108(MarioMantleInterface*) {}
void fn_91_1010C(MarioMantleInterface*) {}
void* fn_91_10110(MarioMantleInterface* mantle) { return mantle->resource; }
int fn_91_10118(MarioMantleInterface*) { return 2; }
float fn_91_10120(MarioMantleInterface*) { return lbl_91_rodata_30; }
bool fn_91_1012C(MarioMantleInterface*) { return false; }
float fn_91_10134(MarioMantleInterface*) { return lbl_91_rodata_34; }
bool fn_91_10140(MarioMantleInterface*) { return false; }
float fn_91_10148(MarioMantleInterface*) { return lbl_91_rodata_30; }
float fn_91_10154(MarioMantleInterface*) { return lbl_91_rodata_30; }
bool fn_91_10160(MarioMantleInterface*) { return false; }
void fn_91_10168(MarioMantleInterface*) {}
void fn_91_1016C(MarioMantleInterface*) {}
void fn_91_10170(MarioMantleInterface*) {}
}
