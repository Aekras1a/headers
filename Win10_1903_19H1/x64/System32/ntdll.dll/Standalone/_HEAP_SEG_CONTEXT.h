typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0008 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0010 */

typedef struct _RTL_RB_TREE
{
  /* 0x0000 */ struct _RTL_BALANCED_NODE* Root;
  union
  {
    /* 0x0008 */ unsigned char Encoded : 1; /* bit position: 0 */
    /* 0x0008 */ struct _RTL_BALANCED_NODE* Min;
  }; /* size: 0x0008 */
} RTL_RB_TREE, *PRTL_RB_TREE; /* size: 0x0010 */

typedef struct _SINGLE_LIST_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY; /* size: 0x0008 */

struct RTL_HP_ENV_HANDLE
{
  /* 0x0000 */ void* h[2];
}; /* size: 0x0010 */

typedef struct _HEAP_SEG_CONTEXT
{
  /* 0x0000 */ unsigned __int64 SegmentMask;
  /* 0x0008 */ unsigned char UnitShift;
  /* 0x0009 */ unsigned char PagesPerUnitShift;
  /* 0x000a */ unsigned char FirstDescriptorIndex;
  /* 0x000b */ unsigned char CachedCommitSoftShift;
  /* 0x000c */ unsigned char CachedCommitHighShift;
  union // _TAG_UNNAMED_32
  {
    union
    {
      struct /* bitfield */
      {
        /* 0x000d */ unsigned char FullDecommit : 1; /* bit position: 0 */
        /* 0x000d */ unsigned char ReleaseEmptySegments : 1; /* bit position: 1 */
        /* 0x000d */ unsigned char OpportunisticLargePages : 1; /* bit position: 2 */
        /* 0x000d */ unsigned char ForceLargePages : 2; /* bit position: 3 */
      }; /* bitfield */
      /* 0x000d */ unsigned char AllFlags;
    }; /* size: 0x0001 */
  } /* size: 0x0001 */ Flags;
  /* 0x0010 */ unsigned long MaxAllocationSize;
  /* 0x0018 */ unsigned __int64 SegmentLock;
  /* 0x0020 */ struct _LIST_ENTRY SegmentListHead;
  /* 0x0030 */ unsigned __int64 SegmentCount;
  /* 0x0038 */ struct _RTL_RB_TREE FreePageRanges;
  /* 0x0048 */ unsigned __int64 FreeSegmentListLock;
  /* 0x0050 */ struct _SINGLE_LIST_ENTRY FreeSegmentList[2];
  /* 0x0060 */ struct _HEAP_OPPORTUNISTIC_LARGE_PAGE_STATS* OlpStats;
  /* 0x0068 */ struct _HEAP_RUNTIME_MEMORY_STATS* MemStats;
  /* 0x0070 */ void* LfhContext;
  /* 0x0078 */ void* VsContext;
  /* 0x0080 */ struct RTL_HP_ENV_HANDLE EnvHandle;
  /* 0x0090 */ void* Heap;
} HEAP_SEG_CONTEXT, *PHEAP_SEG_CONTEXT; /* size: 0x0098 */

