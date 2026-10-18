#pragma force_active on
#pragma metrics enum 8

extern "C" const float lbl_108_rodata_18;

extern "C" struct Pair { float pad[2]; float b; float a; };

extern "C" void fn_108_10AF0(Pair* object) {
    object->a = lbl_108_rodata_18;
    object->b = lbl_108_rodata_18;
}
