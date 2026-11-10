
typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
typedef enum 
{
  PF_RESULT_OK = 0,
  PF_RESULT_INVALID = 10
} PFResult;
typedef struct PF_ENT_ITER
{
  char _0x0[0x8];
  u32 _0x8;
  char _0xC[0x2c];
  void *unk;
  char _0x3c[0x31];
} PF_ENT_ITER;
typedef struct PF_DIR_ENT
{
  char _0x0[0x228];
  u32 _0x228;
  void *cache;
  char _0x230[4];
  u32 _0x234;
  int sector;
  short offset;
} PF_DIR_ENT;
int PFSEC_ReadData(void *cache, void *buffer, int sector, int offset, int len, int *success, int unk);
int PFSEC_WriteData(void *cache, void *buffer, int sector, int offset, int len, int *success, int unk);
#pragma force_active on
typedef struct 
{
  unsigned short unk00;
  char pad02[0x1E];
  unsigned char unk20;
  char pad21[0x243];
  int unk264;
  int unk268;
} Node;
typedef struct 
{
  int unk00;
  int unk04;
  Node *node;
  int pad0C[4];
  unsigned int unk1C;
  int unk20;
  int unk24;
  unsigned short unk28;
} Obj;
extern int fn_803E1494(void *, int, int, void *, int *);
extern void fn_803DAAE8(void *, int);
inline unsigned int inline_fn(Obj *arg0, int arg1)
{
  return arg0->unk1C >> ((Node *) arg1)->unk20;
}

int fn_803E4000(Obj *self, void *buffer, unsigned int length, int *bytesWritten)
{
  int spC;
  int sp8;
  int new_var[2];
  int r;
  int ptr;
  unsigned int n;
  unsigned int oldUnk20;
  unsigned int temp;
  *bytesWritten = 0;
  spC = 0;
  r = fn_803E1494(((char *) self->node) + 4, self->unk24, length, ((char *) self) + 0x20, &spC);
  if (r != 0)
  {
    return r;
  }
  if (((unsigned int) (self->unk20 + 0x10000)) == 0xFFFF)
  {
    self->unk1C = self->node->unk264;
    if (self == 0)
    {
      ptr = 0;
    }
    else
    {
      ptr = self->node->unk268;
    }
    self->unk24 = inline_fn(self, ptr);
    self->unk28 = self->unk1C & (((Node *) ptr)->unk00 - 1);
    return 0x1C;
  }
  if (self == 0)
  {
    new_var[0] = 0;
  }
  else
  {
    new_var[0] = self->node->unk268;
  }
  if (length > ((unsigned int) (spC << ((Node *) new_var[0])->unk20)))
  {
    length = spC << ((Node *) new_var[0])->unk20;
  }
  r = PFSEC_WriteData((void *) new_var[0], buffer, self->unk20, self->unk28, length, &sp8, 1);
  if ((r != 0) && (sp8 == 0))
  {
    return r;
  }
  *bytesWritten = sp8;
  oldUnk20 = self->unk20;
  n = sp8;
  if (self == 0)
  {
    ptr = 0;
  }
  else
  {
    ptr = self->node->unk268;
  }
  temp = self->unk28 + n;
  new_var[1] = oldUnk20 + (temp >> ((Node *) ptr)->unk20);
  if ((((Node *) ptr)->unk00 - 1) & temp)
  {
    self->unk20 = new_var[1];
  }
  else
  {
    self->unk20 = -1;
  }
  self->unk1C += n;
  if (self->unk1C > ((unsigned int) self->node->unk264))
  {
    self->node->unk264 = self->unk1C;
  }
  if (self == 0)
  {
    ptr = 0;
  }
  else
  {
    ptr = self->node->unk268;
  }
  self->unk24 = self->unk1C >> ((Node *) ptr)->unk20;
  self->unk28 = self->unk1C & (((Node *) ptr)->unk00 - 1);
  fn_803DAAE8(self, (int) new_var[1]);
  if (((unsigned int) sp8) != (length - (length & (((Node *) new_var[0])->unk00 - 1))))
  {
    return r;
  }
  return 0;
}
