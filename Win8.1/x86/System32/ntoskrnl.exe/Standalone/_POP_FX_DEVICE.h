typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef union _POP_FX_DEVICE_STATUS
{
  union
  {
    /* 0x0000 */ long Value;
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long SystemTransition : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long PepD0Notify : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long IdleTimerOn : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long IgnoreIdleTimeout : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long IrpInUse : 1; /* bit position: 4 */
      /* 0x0000 */ unsigned long IrpPending : 1; /* bit position: 5 */
      /* 0x0000 */ unsigned long DPNRDeviceNotified : 1; /* bit position: 6 */
      /* 0x0000 */ unsigned long DPNRReceivedFromPep : 1; /* bit position: 7 */
      /* 0x0000 */ unsigned long Reserved : 24; /* bit position: 8 */
    }; /* bitfield */
  }; /* size: 0x0004 */
} POP_FX_DEVICE_STATUS, *PPOP_FX_DEVICE_STATUS; /* size: 0x0004 */

typedef struct _POP_FX_DRIVER_CALLBACKS
{
  /* 0x0000 */ void* ComponentActive /* function */;
  /* 0x0004 */ void* ComponentIdle /* function */;
  /* 0x0008 */ void* ComponentIdleState /* function */;
  /* 0x000c */ void* DevicePowerRequired /* function */;
  /* 0x0010 */ void* DevicePowerNotRequired /* function */;
  /* 0x0014 */ void* PowerControl /* function */;
  /* 0x0018 */ void* ComponentCriticalTransition /* function */;
} POP_FX_DRIVER_CALLBACKS, *PPOP_FX_DRIVER_CALLBACKS; /* size: 0x001c */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char QueueControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Abandoned : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char DisableIncrement : 1; /* bit position: 1 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Signalling;
        /* 0x0001 */ unsigned char Timer2Flags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Timer2Inserted : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char Timer2Expiring : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char Timer2CancelPending : 1; /* bit position: 2 */
            /* 0x0001 */ unsigned char Timer2SetPending : 1; /* bit position: 3 */
            /* 0x0001 */ unsigned char Timer2Running : 1; /* bit position: 4 */
            /* 0x0001 */ unsigned char Timer2Disabled : 1; /* bit position: 5 */
            /* 0x0001 */ unsigned char Reserved1 : 2; /* bit position: 6 */
          }; /* bitfield */
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved2 : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            /* 0x0002 */ unsigned char Reserved3;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
                /* 0x0003 */ unsigned char Reserved5;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _IO_REMOVE_LOCK_COMMON_BLOCK
{
  /* 0x0000 */ unsigned char Removed;
  /* 0x0001 */ unsigned char Reserved[3];
  /* 0x0004 */ long IoCount;
  /* 0x0008 */ struct _KEVENT RemoveEvent;
} IO_REMOVE_LOCK_COMMON_BLOCK, *PIO_REMOVE_LOCK_COMMON_BLOCK; /* size: 0x0018 */

typedef struct _IO_REMOVE_LOCK
{
  /* 0x0000 */ struct _IO_REMOVE_LOCK_COMMON_BLOCK Common;
} IO_REMOVE_LOCK, *PIO_REMOVE_LOCK; /* size: 0x0018 */

typedef struct _WORK_QUEUE_ITEM
{
  /* 0x0000 */ struct _LIST_ENTRY List;
  /* 0x0008 */ void* WorkerRoutine /* function */;
  /* 0x000c */ void* Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM; /* size: 0x0010 */

typedef struct _POP_FX_WORK_ORDER
{
  /* 0x0000 */ struct _WORK_QUEUE_ITEM WorkItem;
  /* 0x0010 */ long WorkCount;
  /* 0x0014 */ void* Context;
  /* 0x0018 */ struct _POP_FX_WORK_ORDER_WATCHDOG_INFO* WatchdogTimerInfo;
} POP_FX_WORK_ORDER, *PPOP_FX_WORK_ORDER; /* size: 0x001c */

typedef union _ULARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    }; /* size: 0x0008 */
    struct // _TAG_UNNAMED_19
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ unsigned __int64 QuadPart;
  }; /* size: 0x0008 */
} ULARGE_INTEGER, *PULARGE_INTEGER; /* size: 0x0008 */

typedef struct _KTIMER
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ union _ULARGE_INTEGER DueTime;
  /* 0x0018 */ struct _LIST_ENTRY TimerListEntry;
  /* 0x0020 */ struct _KDPC* Dpc;
  /* 0x0024 */ unsigned long Period;
} KTIMER, *PKTIMER; /* size: 0x0028 */

typedef struct _SINGLE_LIST_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY; /* size: 0x0004 */

typedef struct _KDPC
{
  union
  {
    /* 0x0000 */ unsigned long TargetInfoAsUlong;
    struct
    {
      /* 0x0000 */ unsigned char Type;
      /* 0x0001 */ unsigned char Importance;
      /* 0x0002 */ volatile unsigned short Number;
    }; /* size: 0x0004 */
  }; /* size: 0x0004 */
  /* 0x0004 */ struct _SINGLE_LIST_ENTRY DpcListEntry;
  /* 0x0008 */ unsigned long ProcessorHistory;
  /* 0x000c */ void* DeferredRoutine /* function */;
  /* 0x0010 */ void* DeferredContext;
  /* 0x0014 */ void* SystemArgument1;
  /* 0x0018 */ void* SystemArgument2;
  /* 0x001c */ void* DpcData;
} KDPC, *PKDPC; /* size: 0x0020 */

typedef enum _SYSTEM_POWER_STATE
{
  PowerSystemUnspecified = 0,
  PowerSystemWorking = 1,
  PowerSystemSleeping1 = 2,
  PowerSystemSleeping2 = 3,
  PowerSystemSleeping3 = 4,
  PowerSystemHibernate = 5,
  PowerSystemShutdown = 6,
  PowerSystemMaximum = 7,
} SYSTEM_POWER_STATE, *PSYSTEM_POWER_STATE;

typedef enum _DEVICE_POWER_STATE
{
  PowerDeviceUnspecified = 0,
  PowerDeviceD0 = 1,
  PowerDeviceD1 = 2,
  PowerDeviceD2 = 3,
  PowerDeviceD3 = 4,
  PowerDeviceMaximum = 5,
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE;

typedef union _POWER_STATE
{
  union
  {
    /* 0x0000 */ enum _SYSTEM_POWER_STATE SystemState;
    /* 0x0000 */ enum _DEVICE_POWER_STATE DeviceState;
  }; /* size: 0x0004 */
} POWER_STATE, *PPOWER_STATE; /* size: 0x0004 */

typedef struct _POP_FX_ACCOUNTING
{
  /* 0x0000 */ unsigned long Lock;
  /* 0x0004 */ unsigned char Active;
  /* 0x0008 */ unsigned long DripsRequiredState;
  /* 0x000c */ long Level;
  /* 0x0010 */ __int64 ActiveStamp;
  /* 0x0018 */ unsigned __int64 CsActiveTime;
  /* 0x0020 */ __int64 CriticalActiveTime;
} POP_FX_ACCOUNTING, *PPOP_FX_ACCOUNTING; /* size: 0x0028 */

typedef struct _POP_FX_DEVICE
{
  /* 0x0000 */ struct _LIST_ENTRY Link;
  /* 0x0008 */ struct _IRP* Irp;
  /* 0x000c */ struct _POP_IRP_DATA* IrpData;
  /* 0x0010 */ volatile union _POP_FX_DEVICE_STATUS Status;
  /* 0x0014 */ volatile long PowerReqCall;
  /* 0x0018 */ volatile long PowerNotReqCall;
  /* 0x001c */ struct _POP_FX_PLUGIN* Plugin;
  /* 0x0020 */ struct PEPHANDLE__* PluginHandle;
  /* 0x0024 */ struct _POP_FX_PLUGIN* MiniPlugin;
  /* 0x0028 */ struct PEPHANDLE__* MiniPluginHandle;
  /* 0x002c */ struct _DEVICE_NODE* DevNode;
  /* 0x0030 */ struct _DEVICE_OBJECT* DeviceObject;
  /* 0x0034 */ struct _DEVICE_OBJECT* TargetDevice;
  /* 0x0038 */ struct _POP_FX_DRIVER_CALLBACKS Callbacks;
  /* 0x0054 */ void* DriverContext;
  /* 0x0058 */ struct _IO_REMOVE_LOCK RemoveLock;
  /* 0x0070 */ struct _POP_FX_WORK_ORDER WorkOrder;
  /* 0x008c */ unsigned long IdleLock;
  /* 0x0090 */ struct _KTIMER IdleTimer;
  /* 0x00b8 */ struct _KDPC IdleDpc;
  /* 0x00d8 */ unsigned __int64 IdleTimeout;
  /* 0x00e0 */ unsigned __int64 IdleStamp;
  /* 0x00e8 */ struct _DEVICE_OBJECT* NextIrpDeviceObject;
  /* 0x00ec */ union _POWER_STATE NextIrpPowerState;
  /* 0x00f0 */ void* NextIrpCallerCompletion /* function */;
  /* 0x00f4 */ void* NextIrpCallerContext;
  /* 0x00f8 */ struct _KEVENT IrpCompleteEvent;
  /* 0x0108 */ void* PowerOnDumpDeviceCallback /* function */;
  /* 0x0110 */ struct _POP_FX_ACCOUNTING Accounting;
  /* 0x0138 */ unsigned long ComponentCount;
  /* 0x013c */ struct _POP_FX_COMPONENT* Components[1];
} POP_FX_DEVICE, *PPOP_FX_DEVICE; /* size: 0x0140 */

