#pragma force_active on

typedef unsigned char u8;

struct Manager {
    u8 pad[0x138];
    int count;
};

struct Handle {
    unsigned int data[2];
};

extern "C" {
extern u8 lbl_8042EC30[];
extern Manager* lbl_805A0110;

int fn_8016FBC8(void*);
void* fn_801647B4();
void fn_8005AD04();
int fn_8016FBF4(void*);
void fn_80163F28();
void fn_80163E50(int);
void fn_80164A84(void*, int);
void fn_8016FB7C(Handle*);
void fn_8016FB8C(void*, Handle*);
void fn_8005A820(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_8005C798(u8* self, int deleting)
{
    if (self) {
        *reinterpret_cast<void**>(self + 0x48) = lbl_8042EC30;

        if (fn_8016FBC8(self + 0x4C) != 0) {
            int handle;
            void* manager = fn_801647B4();

            if (((unsigned int)(self[0x54] >> 3) & 1) == 1) {
                if (!lbl_805A0110) {
                    fn_8005AD04();
                }
                if (lbl_805A0110->count > 0) {
                    --lbl_805A0110->count;
                }
            }

            handle = fn_8016FBF4(self + 0x4C);
            fn_80163F28();
            fn_80163E50(handle);
            fn_80164A84(manager, handle);

            Handle empty;
            fn_8016FB7C(&empty);
            fn_8016FB8C(self + 0x4C, &empty);
        }

        fn_8005A820(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
