.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global Reset_Handler
.global _estack

.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word MemManage_Handler
  .word BusFault_Handler
  .word UsageFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word DebugMon_Handler
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler

/* Define weak default handlers */
.section .text.Default_Handler, "ax", %progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop

.weak NMI_Handler
.weak HardFault_Handler
.weak MemManage_Handler
.weak BusFault_Handler
.weak UsageFault_Handler
.weak SVC_Handler
.weak DebugMon_Handler
.weak PendSV_Handler
.weak SysTick_Handler

NMI_Handler:            b Default_Handler
HardFault_Handler:      b Default_Handler
MemManage_Handler:      b Default_Handler
BusFault_Handler:       b Default_Handler
UsageFault_Handler:     b Default_Handler
SVC_Handler:            b Default_Handler
DebugMon_Handler:       b Default_Handler
PendSV_Handler:         b Default_Handler
SysTick_Handler:        b Default_Handler

/* Entry point */
.section .text.Reset_Handler
Reset_Handler:
  bl  SystemInit
  bl  main
  b   .
