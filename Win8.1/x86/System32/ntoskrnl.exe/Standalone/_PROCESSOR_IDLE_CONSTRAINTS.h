typedef struct _PROCESSOR_IDLE_CONSTRAINTS
{
  /* 0x0000 */ unsigned __int64 TotalTime;
  /* 0x0008 */ unsigned __int64 IdleTime;
  /* 0x0010 */ unsigned __int64 ExpectedIdleDuration;
  /* 0x0018 */ unsigned __int64 MaxIdleDuration;
  /* 0x0020 */ unsigned long OverrideState;
  /* 0x0024 */ unsigned long TimeCheck;
  /* 0x0028 */ unsigned char PromotePercent;
  /* 0x0029 */ unsigned char DemotePercent;
  /* 0x002a */ unsigned char Parked;
  /* 0x002b */ unsigned char Interruptible;
  /* 0x002c */ unsigned char PlatformIdle;
  /* 0x0030 */ unsigned long IRHints;
  /* 0x0034 */ unsigned long IRTruncatedHints;
  /* 0x0038 */ unsigned char ExpectedWakeReason;
  /* 0x0039 */ char __PADDING__[7];
} PROCESSOR_IDLE_CONSTRAINTS, *PPROCESSOR_IDLE_CONSTRAINTS; /* size: 0x0040 */

