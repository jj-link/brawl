#pragma force_active on
extern "C" int fn_27_8BC8C(void*, void*, int, int);
extern "C" int fn_41_A468(void*, int);
extern "C" void* getCurrentAIInfo__14emAIModuleImplFv(void*);
extern "C" void* fn_41_29818(void*, unsigned int);
extern "C" int fn_41_B4C4(void*);
extern "C" int fn_41_B6C8(void*);
extern "C" int fn_41_B744(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];

extern "C" int fn_41_22118(void* self, void* acc, int param, int extra) {
    if (param <= 0x5207) {
        return fn_27_8BC8C(self, acc, param, extra);
    }

    switch (param) {
    case 0x5208:
        return fn_41_A468(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1), 0);
    case 0x5209:
        return fn_41_A468(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1), 1);
    case 0x5210:
        return fn_41_A468(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1), 3);
    case 0x520A:
        return fn_41_A468(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1), 2);
    case 0x520B:
        return *(int*)getCurrentAIInfo__14emAIModuleImplFv((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0x1108);
    case 0x520C:
        return *(int*)((char*)getCurrentAIInfo__14emAIModuleImplFv((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0x1108) + 4);
    case 0x520D:
        return *(int*)fn_41_29818((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0x1108, 0);
    case 0x520E:
        return *(int*)((char*)fn_41_29818((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0x1108, 0) + 4);
    case 0x520F:
        return *(int*)((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0xAC);
    case 0x5211:
        return *(int*)((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0xB4);
    case 0x5212:
        return *(int*)((char*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1) + 0xBC);
    case 0x5213:
        return fn_41_B6C8(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1));
    case 0x5215:
        return fn_41_B744(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1));
    case 0x5214:
        return fn_41_B4C4(__dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1));
    default:
        return 0;
    }
}
