#pragma force_active on
typedef unsigned int u32;

extern "C" void Init__Q34nw4r3g3d7ResFileFPv(void* self, void* arg);

extern "C" void* fn_8010CF44(void* self, void* arg, u32 unused, u32 arg3) {
    *(u32*)self = arg3;
    Init__Q34nw4r3g3d7ResFileFPv(self, arg);
    *(void**)((char*)self + 4) = arg;
    return self;
}
