#include <stdint.h>

/* Function prototypes */
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void Default_Handler(void);

/* Linker script symbols */
extern uint32_t _estack;

/* Define the vector table structure */
typedef struct {
    void* pvStack;
    void* pfnReset_Handler;
    void* pfnNMI_Handler;
    void* pfnHardFault_Handler;
    void* pfnMemManage_Handler;
    void* pfnBusFault_Handler;
    void* pfnUsageFault_Handler;
    void* reserved1[4];
    void* pfnSVC_Handler;
    void* pfnDebugMon_Handler;
    void* reserved2;
    void* pfnPendSV_Handler;
    void* pfnSysTick_Handler;
    void* pfnIRQ[45]; // Adjust this count per SAM4E vector count
} DeviceVectors;

/* The actual vector table */
__attribute__ ((section(".isr_vector")))
const DeviceVectors exception_table = {
    .pvStack = (void*) (&_estack),
    .pfnReset_Handler = Reset_Handler,
    .pfnNMI_Handler = NMI_Handler,
    .pfnHardFault_Handler = HardFault_Handler,
    .pfnMemManage_Handler = MemManage_Handler,
    .pfnBusFault_Handler = BusFault_Handler,
    .pfnUsageFault_Handler = UsageFault_Handler,
    .reserved1 = { 0, 0, 0, 0 },
    .pfnSVC_Handler = SVC_Handler,
    .pfnDebugMon_Handler = DebugMon_Handler,
    .reserved2 = 0,
    .pfnPendSV_Handler = PendSV_Handler,
    .pfnSysTick_Handler = SysTick_Handler,
    .pfnIRQ = {
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler, Default_Handler,
        Default_Handler, Default_Handler, Default_Handler
    }
};

/* Default handler */
void Default_Handler(void) {
    while (1);
}

/* Stub implementations of core handlers */
void Reset_Handler(void)      { while (1); }
void NMI_Handler(void)        { while (1); }
void HardFault_Handler(void)  { while (1); }
void MemManage_Handler(void)  { while (1); }
void BusFault_Handler(void)   { while (1); }
void UsageFault_Handler(void) { while (1); }
void SVC_Handler(void)        { while (1); }
void DebugMon_Handler(void)   { while (1); }
void PendSV_Handler(void)     { while (1); }
void SysTick_Handler(void)    { while (1); }
