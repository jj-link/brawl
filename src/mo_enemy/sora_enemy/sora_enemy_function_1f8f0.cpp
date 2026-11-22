#include <so/so_value_accesser.h>
#include <mt/mt_matrix.h>
#include <new>
inline void* operator new[](size_t, void* p) { return p; }
#pragma force_active on
#pragma inline_depth(8)

namespace dispatch {
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
    virtual void fn_41_135B0();
    virtual void fn_41_135A4();
    virtual void fn_41_135A0();
    virtual Vec2f fn_41_12D6C(short*);
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_41_1F8F0();
    virtual void fn_41_1F890();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void* fn_41_350A4(int);
    virtual int fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
};
}
struct Argument {
    void* value;
    bool null;
    Argument(void* v) : value(v), null(false) {}
};
inline Argument argument(dispatch::Class_6E20* event, int index) {
    return Argument(event->fn_41_350A4(index));
}
extern "C" {
extern const float lbl_41_rodata_D28[];
extern const char __RTTI__5Enemy[], __RTTI__11StageObject[];
extern const char lbl_41_data_644[], lbl_41_data_6A8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_41_A1C4(Argument);
unsigned int fn_41_A1E4(Argument);
int fn_41_A184(Argument);
const char* fn_41_A1A4(Argument);
float fn_41_A204(Argument);
unsigned int fn_41_A25C(Argument);
int fn_41_A27C(Argument);
int fn_41_2988C(void*, void*, unsigned int);
int fn_41_17FBC(void*, int);
int fn_41_1805C(void*, int);
int fn_41_180FC(void*, int);
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void fn_41_534C(Vec3f*, const Vec3f*);
Vec2f* fn_41_2354(Vec2f*, float, float);
void fn_8003E3BC(Matrix*, Vec3f*, Vec3f*);
int fn_41_24D74(soModuleAccesser*, int, Vec2f, Vec2f, int);
int fn_41_25848(soModuleAccesser*, int, Vec2f, Vec2f, int);
int fn_41_25034(soModuleAccesser*, int, Vec2f, Vec2f, int);
int fn_41_2594C(soModuleAccesser*, int, Vec2f, Vec2f, int);
int fn_41_15E38(soModuleAccesser*, const Vec2f&, int);
int fn_41_5780(void*, unsigned int*, unsigned int, Vec2f*);
int fn_41_58C8(void*, unsigned int*, unsigned int, Vec2f*);
int fn_27_7B610(void*, int, dispatch::Class_6E20*, soModuleAccesser*);
}
#define ARG(i) argument(event, i)
#define TYPE(i) fn_41_A1C4(ARG(i))
#define ID(i) fn_41_A1E4(ARG(i))
#define SET_FLOAT(dst, i) do { if (TYPE(i) == 5) dst = soValueAccesser::getValueFloat(accesser, ID(i), 0); else dst = fn_41_A204(ARG(i)); } while (0)
#define SET_INTEGER(dst, i) do { if (TYPE(i) == 5) dst = (int)soValueAccesser::getValueFloat(accesser, ID(i), 0); else dst = fn_41_A184(ARG(i)); } while (0)

inline Vec2f* temporary(const Vec2f& v) {
    return const_cast<Vec2f*>(&v);
}
#pragma pack(push, 4)
union PositionResult {
    unsigned long long bits;
    struct {float x,y;} values;
};
#pragma pack(pop)
struct Frame {
    Vec2f position, speed2, speed1, base, speed0;
    Vec3f c6,c5,c4,c3,c2,c1;
    Vec3f b6,b5,b4,b3,b2,b1;
    Vec3f a3,a2,a1;
    Vec3f dir2,dir1,dir0;
    unsigned int objects[5];
    Matrix matrix2,matrix1,matrix0;
    Frame() : matrix2(true), matrix1(true), matrix0(true) {}
};

extern "C" int fn_41_1F8F0(void* self, int command, dispatch::Class_6E20* event, soModuleAccesser* accesser) {
    const float* data = lbl_41_rodata_D28;
    Frame f;
    int count = event->fn_41_350AC();
    switch(command) {
    case 0x3e8: {
        if (count < 2 || count > 2) return -1;
        void* object;
        if (TYPE(0) == 5)
            object = soValueAccesser::getConstantIndefinite(accesser, ID(0), 0);
        else
            object = (void*)fn_41_A25C(ARG(0));
        unsigned int value;
        if (TYPE(1) == 5)
            value = (unsigned int)soValueAccesser::getValueFloat(accesser, ID(1), 0);
        else
            value = fn_41_A184(ARG(1));
        char* enemy = (char*)__dynamic_cast(accesser->m_stageObject, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        return fn_41_2988C(enemy+0x1108, object, value);
    }
    case 0x3e9: case 0x3ea: case 0x3eb: {
        if (count < 1 || count > 1) return -1;
        int value;
        if (TYPE(0) == 5)
            value = soValueAccesser::getValueInt(accesser, ID(0), 0);
        else
            value = fn_41_A184(ARG(0));
        void* module = __dynamic_cast(*(void**)((char*)accesser->m_enumerationStart+0x7c), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        if (command == 0x3e9) return fn_41_17FBC(module, value);
        else if (command == 0x3ea) return fn_41_1805C(module, value);
        else if (command == 0x3eb) return fn_41_180FC(module, value);
        return -1;
    }
    case 0x3ec: case 0x3ed: case 0x3ee: case 0x3ef: case 0x3f0: case 0x3f1:
    case 0x3f3: case 0x3f4: case 0x3f5: case 0x3f6: case 0x3f7: case 0x3f8: {
        if (count < 5 || count > 5) return 3;
        soModelModule* model = &accesser->getModelModule();
        int node;
        if(command == 0x3ec || command == 0x3ed || command == 0x3ee ||
            ((unsigned int)(command - 0x3f3) <= 2))
            SET_INTEGER(node, 0);
        else if(command == 0x3ef || command == 0x3f0 || command == 0x3f1 ||
            ((unsigned int)(command - 0x3f6) <= 2))
            node = model->getNodeId(fn_41_A1A4(ARG(0)));
        else return 3;
        model->getNodeGlobalMtx(node, &f.matrix0, false);
        fn_41_5AC4(&f.dir0, data[0],data[0],data[0]);
        if(command == 0x3ec || command == 0x3f3 || command == 0x3ef || command == 0x3f6)
            fn_41_534C(&f.dir0, fn_41_5AC4(&f.a1,data[1],data[0],data[0]));
        else if(command == 0x3ed || command == 0x3f4 || command == 0x3f0 || command == 0x3f7)
            fn_41_534C(&f.dir0, fn_41_5AC4(&f.a2,data[0],data[1],data[0]));
        else if(command == 0x3ee || command == 0x3f5 || command == 0x3f1 || command == 0x3f8)
            fn_41_534C(&f.dir0, fn_41_5AC4(&f.a3,data[0],data[0],data[1]));
        fn_8003E3BC(&f.matrix0,&f.dir0,&f.dir0);
        int value;
        SET_INTEGER(value, 1);
        f.speed0.m_x = data[0]; f.speed0.m_y = data[0];
        SET_FLOAT(f.speed0.m_x, 2);
        SET_FLOAT(f.speed0.m_y, 3);
        int flag = fn_41_A27C(ARG(4));
        if((unsigned int)(command - 0x3ec) <= 5) {
            return fn_41_24D74(accesser,value,f.speed0,*fn_41_2354(temporary(Vec2f()),f.dir0.m_x,f.dir0.m_y),flag);
        }
        else if((unsigned int)(command - 0x3f3) <= 5) {
            return fn_41_25848(accesser,value,f.speed0,*fn_41_2354(temporary(Vec2f()),f.dir0.m_x,f.dir0.m_y),flag);
        }
        break;
    }
    case 0x3f2: case 0x3f9: {
        if (count < 4 || count > 4) return 3;
        f.base.m_x = data[0]; f.base.m_y = data[0];
        short index = -1;
        f.base = (*(dispatch::soAnimCmdEventObserver**)((char*)accesser->m_enumerationStart+0x7c))->fn_41_12D6C(&index);
        int value;
        SET_INTEGER(value, 0);
        f.speed1.m_x = data[0]; f.speed1.m_y = data[0];
        SET_FLOAT(f.speed1.m_x, 1);
        SET_FLOAT(f.speed1.m_y, 2);
        int flag = fn_41_A27C(ARG(3));
        if(command == 0x3f2) return fn_41_24D74(accesser,value,f.speed1,f.base,flag);
        else if(command == 0x3f9) return fn_41_25848(accesser,value,f.speed1,f.base,flag);
        break;
    }
    case 0x3fa: case 0x3fb: case 0x3fc: case 0x3fd: case 0x3fe: case 0x3ff:
    case 0x400: case 0x401: case 0x402: case 0x403: case 0x404: case 0x405:
    case 0x406: case 0x407: case 0x408: case 0x409: case 0x40a: case 0x40b:
    case 0x40c: case 0x40d: case 0x40e: case 0x40f: case 0x410: case 0x411: {
        if (count < 5 || count > 5) return 3;
        soModelModule* model = &accesser->getModelModule();
        int node;
        if(command == 0x3fa || command == 0x3fb || command == 0x3fc ||
           command == 0x400 || command == 0x401 || command == 0x402 ||
           command == 0x406 || command == 0x407 || command == 0x408 ||
           ((unsigned int)(command - 0x40c) <= 2))
            SET_INTEGER(node, 0);
        else if(command == 0x3fd || command == 0x3fe || command == 0x3ff ||
           command == 0x403 || command == 0x404 || command == 0x405 ||
           command == 0x409 || command == 0x40a || command == 0x40b ||
           ((unsigned int)(command - 0x40f) <= 2))
            node = model->getNodeId(fn_41_A1A4(ARG(0)));
        else return 3;
        model->getNodeGlobalMtx(node, &f.matrix1, false);
        fn_41_5AC4(&f.dir1,data[0],data[0],data[0]);
        if(command == 0x3fa || command == 0x400 || command == 0x3fd || command == 0x403)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b1,data[1],data[0],data[0]));
        else if(command == 0x3fb || command == 0x401 || command == 0x3fe || command == 0x404)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b2,data[0],data[1],data[0]));
        else if(command == 0x3fc || command == 0x402 || command == 0x3ff || command == 0x405)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b3,data[0],data[0],data[1]));
        else if(command == 0x406 || command == 0x40c || command == 0x409 || command == 0x40f)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b4,data[2],data[0],data[0]));
        else if(command == 0x407 || command == 0x40d || command == 0x40a || command == 0x410)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b5,data[0],data[2],data[0]));
        else if(command == 0x408 || command == 0x40e || command == 0x40b || command == 0x411)
            fn_41_534C(&f.dir1,fn_41_5AC4(&f.b6,data[0],data[0],data[2]));
        fn_8003E3BC(&f.matrix1,&f.dir1,&f.dir1);
        int value;
        SET_INTEGER(value, 1);
        f.speed2.m_x = data[0]; f.speed2.m_y = data[0];
        SET_FLOAT(f.speed2.m_x, 2);
        SET_FLOAT(f.speed2.m_y, 3);
        int flag = fn_41_A27C(ARG(4));
        if(command == 0x3fa || command == 0x3fb || command == 0x3fc ||
           command == 0x3fd || command == 0x3fe || command == 0x3ff ||
           ((unsigned int)(command - 0x406) <= 5)) {
            return fn_41_25034(accesser,value,f.speed2,*fn_41_2354(temporary(Vec2f()),f.dir1.m_x,f.dir1.m_y),flag);
        }
        else if(command == 0x403 || command == 0x404 || command == 0x405 ||
           command == 0x400 || command == 0x401 || command == 0x402 ||
           ((unsigned int)(command - 0x40c) <= 5)) {
            return fn_41_2594C(accesser,value,f.speed2,*fn_41_2354(temporary(Vec2f()),f.dir1.m_x,f.dir1.m_y),flag);
        }
        break;
    }
    case 0x412: case 0x413: case 0x414: case 0x415: case 0x416: case 0x417:
    case 0x418: case 0x419: case 0x41a: case 0x41b: case 0x41c: case 0x41d: {
        if (count < 1 || count > 1) return 3;
        soModelModule* model = &accesser->getModelModule();
        int node;
        if(command == 0x412 || command == 0x413 || command == 0x414 ||
           ((unsigned int)(command - 0x418) <= 2))
            SET_INTEGER(node, 0);
        else if(command == 0x415 || command == 0x416 || command == 0x417 ||
           ((unsigned int)(command - 0x41b) <= 2))
            node = model->getNodeId(fn_41_A1A4(ARG(0)));
        else return 3;
        model->getNodeGlobalMtx(node,&f.matrix2,false);
        fn_41_5AC4(&f.dir2,data[0],data[0],data[0]);
        if(command == 0x412 || command == 0x415)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c1,data[1],data[0],data[0]));
        else if(command == 0x413 || command == 0x416)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c2,data[0],data[1],data[0]));
        else if(command == 0x414 || command == 0x417)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c3,data[0],data[0],data[1]));
        else if(command == 0x418 || command == 0x41b)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c4,data[2],data[0],data[0]));
        else if(command == 0x419 || command == 0x41c)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c5,data[0],data[2],data[0]));
        else if(command == 0x41a || command == 0x41d)
            fn_41_534C(&f.dir2,fn_41_5AC4(&f.c6,data[0],data[0],data[2]));
        fn_8003E3BC(&f.matrix2,&f.dir2,&f.dir2);
        return fn_41_15E38(accesser,Vec2f(*(const Vec2f*)&f.dir2),0xff);
    }
    case 0x41e: case 0x41f: {
        if(count < 4 || count > 7) return -1;
        SET_FLOAT(f.position.m_x, 0);
        SET_FLOAT(f.position.m_y, 1);
        new (f.objects) unsigned int[5]();
        unsigned int n=0;
        for(int i=2;i<count;++i) {
            if(TYPE(i) == 5)
                f.objects[n++] = (unsigned int)soValueAccesser::getConstantIndefinite(accesser,ID(i),0);
            else
                f.objects[n++] = fn_41_A25C(ARG(i));
            if(n>=5) break;
        }
        void* enemy = __dynamic_cast(accesser->m_stageObject,0x3c,__RTTI__5Enemy,__RTTI__11StageObject,1);
        if(command == 0x41e) return fn_41_5780(enemy,f.objects,n,&f.position);
        else if(command == 0x41f) return fn_41_58C8(enemy,f.objects,n,&f.position);
        break;
    }
    }
    return fn_27_7B610(self,command,event,accesser);
}
