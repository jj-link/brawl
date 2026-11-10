#pragma force_active on

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
typedef struct Node
{
  char pad[8];
  unsigned char *data;
} Node;
typedef struct Volume
{
  unsigned short size;
  char pad02[0x12];
  unsigned short sector;
  char pad16[0x22];
  unsigned int value;
  char pad3c[0x1f70];
  unsigned short flags;
} Volume;
extern int fn_803DA454(Volume *, int, Node **, int *);
extern void fn_803DA55C(Volume *, Node *);
int fn_803E224C(Volume *vol)
{
  Node *node;
  unsigned int *new_var;
  int unused;
  int count;
  int result = 0;
  int ret;
  unsigned int value;
  unsigned char *data;
  unsigned int *base;
  if (vol->flags & 4)
  {
    ret = fn_803DA454(vol, -1, &node, &unused);
    if (ret != 0)
    {
      return ret;
    }
    result = PFSEC_ReadData(vol, node->data, vol->sector, 0, vol->size, &count, 0);
    if ((result == 0) && (((unsigned int) count) != vol->size))
    {
      result = 0x11;
    }
    if (result == 0)
    {
      new_var = (unsigned int *) node->data;
      base = new_var;
      data = ((unsigned char *) base) + 0x1e8;
      if (((unsigned int) data) & 3)
      {
        ((unsigned char *) base)[0x1e8] = vol->value;
        node->data[0x1e9] = vol->value >> 8;
        node->data[0x1ea] = vol->value >> 16;
        node->data[0x1eb] = vol->value >> 24;
      }
      else
      {
        value = vol->value;
        base[0x7a] = ((value << 24) | ((value << 8) & 0xff0000)) | ((value >> 24) | ((value >> 8) & 0xff00));
      }
      result = PFSEC_WriteData(vol, node->data, vol->sector, 0, vol->size, &count, 0);
      if ((result == 0) && (((unsigned int) count) != vol->size))
      {
        result = 0x11;
      }
    }
    fn_803DA55C(vol, node);
  }
  return result;
}
