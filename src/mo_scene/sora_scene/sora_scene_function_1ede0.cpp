#pragma force_active on
// sora_scene: fn_1_1EDE0
// Original: li r0, 0x0 / stw r0, 0x0(r3) / blr
// A single zero word written through the pointer in r3 (no stack frame needed).

extern "C" void fn_1_1EDE0(int* arg) {
    *arg = 0;
}
