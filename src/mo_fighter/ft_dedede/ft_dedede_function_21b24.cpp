#pragma force_active on
extern "C" {
void fn_117_15728(int kind, const void* input, unsigned char* energies, void* accesser);
}

extern "C" void fn_117_21B24(unsigned char* self, int kind, const void* input, void* accesser) {
    fn_117_15728(kind, input, self + 4, accesser);
}
