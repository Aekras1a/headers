enum POWER_ACTION
{
  PowerActionNone = 0,
  PowerActionReserved = 1,
  PowerActionSleep = 2,
  PowerActionHibernate = 3,
  PowerActionShutdown = 4,
  PowerActionShutdownReset = 5,
  PowerActionShutdownOff = 6,
  PowerActionWarmEject = 7,
};

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

enum POWER_POLICY_DEVICE_TYPE
{
  PolicyDeviceSystemButton = 0,
  PolicyDeviceThermalZone = 1,
  PolicyDeviceBattery = 2,
  PolicyDeviceMemory = 3,
  PolicyInitiatePowerActionAPI = 4,
  PolicySetPowerStateAPI = 5,
  PolicyImmediateDozeS4 = 6,
  PolicySystemIdle = 7,
  PolicyDeviceWakeAlarm = 8,
  PolicyDeviceFan = 9,
  PolicyCsBatterySaver = 10,
  PolicyDeviceMax = 11,
};

enum SYSTEM_POWER_CONDITION
{
  PoAc = 0,
  PoDc = 1,
  PoHot = 2,
  PoConditionMaximum = 3,
};

struct BATTERY_REPORTING_SCALE
{
  /* 0x0000 */ unsigned long Granularity;
  /* 0x0004 */ unsigned long Capacity;
}; /* size: 0x0008 */

struct SYSTEM_POWER_CAPABILITIES
{
  /* 0x0000 */ unsigned char PowerButtonPresent;
  /* 0x0001 */ unsigned char SleepButtonPresent;
  /* 0x0002 */ unsigned char LidPresent;
  /* 0x0003 */ unsigned char SystemS1;
  /* 0x0004 */ unsigned char SystemS2;
  /* 0x0005 */ unsigned char SystemS3;
  /* 0x0006 */ unsigned char SystemS4;
  /* 0x0007 */ unsigned char SystemS5;
  /* 0x0008 */ unsigned char HiberFilePresent;
  /* 0x0009 */ unsigned char FullWake;
  /* 0x000a */ unsigned char VideoDimPresent;
  /* 0x000b */ unsigned char ApmPresent;
  /* 0x000c */ unsigned char UpsPresent;
  /* 0x000d */ unsigned char ThermalControl;
  /* 0x000e */ unsigned char ProcessorThrottle;
  /* 0x000f */ unsigned char ProcessorMinThrottle;
  /* 0x0010 */ unsigned char ProcessorMaxThrottle;
  /* 0x0011 */ unsigned char FastSystemS4;
  /* 0x0012 */ unsigned char Hiberboot;
  /* 0x0013 */ unsigned char WakeAlarmPresent;
  /* 0x0014 */ unsigned char AoAc;
  /* 0x0015 */ unsigned char DiskSpinDown;
  /* 0x0016 */ unsigned char spare3[8];
  /* 0x001e */ unsigned char SystemBatteriesPresent;
  /* 0x001f */ unsigned char BatteriesAreShortTerm;
  /* 0x0020 */ struct BATTERY_REPORTING_SCALE BatteryScale[3];
  /* 0x0038 */ enum _SYSTEM_POWER_STATE AcOnLineWake;
  /* 0x003c */ enum _SYSTEM_POWER_STATE SoftLidWake;
  /* 0x0040 */ enum _SYSTEM_POWER_STATE RtcWake;
  /* 0x0044 */ enum _SYSTEM_POWER_STATE MinDeviceWakeState;
  /* 0x0048 */ enum _SYSTEM_POWER_STATE DefaultLowLatencyWake;
}; /* size: 0x004c */

typedef struct _POP_POWER_ACTION
{
  /* 0x0000 */ unsigned char Updates;
  /* 0x0001 */ unsigned char State;
  /* 0x0002 */ unsigned char Shutdown;
  /* 0x0004 */ enum POWER_ACTION Action;
  /* 0x0008 */ enum _SYSTEM_POWER_STATE LightestState;
  /* 0x000c */ unsigned long Flags;
  /* 0x0010 */ long Status;
  /* 0x0014 */ enum POWER_POLICY_DEVICE_TYPE DeviceType;
  /* 0x0018 */ unsigned long DeviceTypeFlags;
  /* 0x001c */ unsigned char IrpMinor;
  /* 0x001d */ unsigned char Waking;
  /* 0x0020 */ enum _SYSTEM_POWER_STATE SystemState;
  /* 0x0024 */ enum _SYSTEM_POWER_STATE NextSystemState;
  /* 0x0028 */ enum _SYSTEM_POWER_STATE EffectiveSystemState;
  /* 0x002c */ enum _SYSTEM_POWER_STATE CurrentSystemState;
  /* 0x0030 */ struct _POP_SHUTDOWN_BUG_CHECK* ShutdownBugCode;
  /* 0x0038 */ struct _POP_DEVICE_SYS_STATE* DevState;
  /* 0x0040 */ struct _POP_HIBER_CONTEXT* HiberContext;
  /* 0x0048 */ unsigned __int64 WakeTime;
  /* 0x0050 */ unsigned __int64 SleepTime;
  /* 0x0058 */ enum SYSTEM_POWER_CONDITION WakeAlarmSignaled;
  /* 0x0060 */ struct // _TAG_UNNAMED_185
  {
    /* 0x0060 */ unsigned __int64 ProgrammedTime;
    /* 0x0068 */ struct _DIAGNOSTIC_BUFFER* TimerInfo;
  } /* size: 0x0010 */ WakeAlarm[3];
  /* 0x0090 */ struct SYSTEM_POWER_CAPABILITIES FilteredCapabilities;
  /* 0x00dc */ long __PADDING__[1];
} POP_POWER_ACTION, *PPOP_POWER_ACTION; /* size: 0x00e0 */

