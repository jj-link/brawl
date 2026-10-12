class soModuleAccesser;

extern "C" {
void fn_101_10574(short*, const short*);
void fn_101_10CC0(short*, const short*);
void fn_101_10C28(void*, const short*, soModuleAccesser*);
void fn_101_10B40(void*, const short*, soModuleAccesser*);
void fn_101_10A58(void*, const short*, soModuleAccesser*);
void fn_101_10970(void*, const short*, soModuleAccesser*);
void fn_101_10888(void*, const short*, soModuleAccesser*);
void fn_101_107A0(void*, const short*, soModuleAccesser*);
void fn_101_106B8(void*, const short*, soModuleAccesser*);
void fn_101_105D0(void*, const short*, soModuleAccesser*);
}

// The attribute value and each per-array copy are signed 16-bit ABI
// records. Keep separate copies: the called routines receive their addresses.
extern "C" void fn_101_10338(unsigned char* energies, soModuleAccesser* accesser,
                             const short* attributes) {
    short mask;
    short input = *attributes;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_101_10574(&mask, &input);
    fn_101_10CC0(&first, &mask);
    fn_101_10C28(energies + 0x208, &first, accesser);
    fn_101_10CC0(&second, &mask);
    fn_101_10B40(energies + 0x1CC, &second, accesser);
    fn_101_10CC0(&third, &mask);
    fn_101_10A58(energies + 0x180, &third, accesser);
    fn_101_10CC0(&fourth, &mask);
    fn_101_10970(energies + 0x138, &fourth, accesser);
    fn_101_10CC0(&fifth, &mask);
    fn_101_10888(energies + 0xF0, &fifth, accesser);
    fn_101_10CC0(&sixth, &mask);
    fn_101_107A0(energies + 0x98, &sixth, accesser);
    fn_101_10CC0(&seventh, &mask);
    fn_101_106B8(energies + 0x64, &seventh, accesser);
    fn_101_10CC0(&eighth, &mask);
    fn_101_105D0(energies + 0x8, &eighth, accesser);
}
