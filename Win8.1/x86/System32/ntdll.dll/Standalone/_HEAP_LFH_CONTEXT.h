typedef struct _HEAP_LFH_CALLBACKS
{
  /* 0x0000 */ void* Allocate /* function */;
  /* 0x0004 */ void* Free /* function */;
  /* 0x0008 */ void* Commit /* function */;
  /* 0x000c */ void* Decommit /* function */;
} HEAP_LFH_CALLBACKS, *PHEAP_LFH_CALLBACKS; /* size: 0x0010 */

typedef struct _RTL_SRWLOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long Shared : 28; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0004 */
} RTL_SRWLOCK, *PRTL_SRWLOCK; /* size: 0x0004 */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _HEAP_LFH_SUBSEGMENT_OWNER
{
  /* 0x0000 */ unsigned char BucketIndex;
  /* 0x0001 */ unsigned char IsBucket;
  union
  {
    /* 0x0002 */ unsigned short SlotIndex;
    struct
    {
      /* 0x0002 */ unsigned char AffinitySlotMask;
      /* 0x0003 */ unsigned char Spare;
    }; /* size: 0x0002 */
  }; /* size: 0x0002 */
  /* 0x0004 */ unsigned long AvailableSubsegmentCount;
  /* 0x0008 */ struct _RTL_SRWLOCK Lock;
  /* 0x000c */ struct _LIST_ENTRY AvailableSubsegmentList;
  /* 0x0014 */ struct _LIST_ENTRY FullSubsegmentList;
} HEAP_LFH_SUBSEGMENT_OWNER, *PHEAP_LFH_SUBSEGMENT_OWNER; /* size: 0x001c */

typedef struct _HEAP_LFH_BUCKET
{
  /* 0x0000 */ struct _HEAP_LFH_SUBSEGMENT_OWNER State;
  /* 0x001c */ struct _HEAP_LFH_AFFINITY_SLOT* AffinitySlots;
  /* 0x0020 */ unsigned long TotalBlockCount;
  /* 0x0024 */ unsigned long TotalSubsegmentCount;
} HEAP_LFH_BUCKET, *PHEAP_LFH_BUCKET; /* size: 0x0028 */

typedef struct _HEAP_LFH_AFFINITY_SLOT
{
  /* 0x0000 */ struct _HEAP_LFH_SUBSEGMENT_OWNER State;
} HEAP_LFH_AFFINITY_SLOT, *PHEAP_LFH_AFFINITY_SLOT; /* size: 0x001c */

typedef struct _HEAP_LFH_CONTEXT
{
  /* 0x0000 */ void* BackendCtx;
  /* 0x0004 */ struct _HEAP_LFH_CALLBACKS Callbacks;
  /* 0x0014 */ struct _HEAP_LFH_BUCKET Buckets[129];
  /* 0x143c */ struct _HEAP_LFH_AFFINITY_SLOT AffinitySlots[129];
} HEAP_LFH_CONTEXT, *PHEAP_LFH_CONTEXT; /* size: 0x2258 */
