typedef struct _ETW_HW_TRACE_EXT_INTERFACE
{
  /* 0x0000 */ void* StartProcessorTraceOnEachCore /* function */;
  /* 0x0004 */ void* StopProcessorTraceOnEachCore /* function */;
  /* 0x0008 */ void* LogProcessorTraceOnCurrentCore /* function */;
} ETW_HW_TRACE_EXT_INTERFACE, *PETW_HW_TRACE_EXT_INTERFACE; /* size: 0x000c */

