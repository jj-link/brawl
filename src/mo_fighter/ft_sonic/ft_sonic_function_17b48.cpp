#pragma force_active on
struct SonicEnergy;
struct soModuleAccesser;

extern "C" void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
extern "C" void fn_123_17BB4(SonicEnergy*, soModuleAccesser*);
extern "C" void fn_123_17E58(void*, SonicEnergy*, soModuleAccesser*);

extern "C" void fn_123_17B48(int kind, unsigned char* state, soModuleAccesser* accesser) {
    if (kind <= 31) {
        fn_27_1DCC10(kind, state, accesser);
        return;
    }

    switch (kind) {
    case 32: {
        struct LocalFlag { bool value; };
        LocalFlag context = { false };
        fn_123_17BB4(reinterpret_cast<SonicEnergy*>(state), accesser);
        break;
    }
    case 33: {
        struct LocalFlag { bool value; };
        LocalFlag context = { false };
        fn_123_17E58(&context, reinterpret_cast<SonicEnergy*>(state), accesser);
        break;
    }
    }
}
