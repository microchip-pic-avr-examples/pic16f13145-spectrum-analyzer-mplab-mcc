/**
 *  @file clbBitstream.s
 *
 *  @brief CLB bitstream data for the PIC16F13145 device family
 *
 **/
/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/*
    The bitstream data can be accesed from C source code by referencing the 'start_clb_config' symbol as such:

    extern uint16_t start_clb_config;
    uint16_t clbStartAddress = (uint16_t) &start_clb_config;

    IMPORTANT: You must always use the address of these symbols and not the value of the symbols themselves.
               If values instead of addresses are used, the linker will silently generate incorrect code.

    uint16_t clbStartAddress = start_clb_config; // This is incorrect!

    NOTE: This module requires C preprocessing.
          This can be enabled via the command line option: -xassembler-with-cpp
*/


#include <xc.inc>

#if !( defined(_16F13113) || defined(_16F13114) || defined(_16F13115) || \
       defined(_16F13123) || defined(_16F13124) || defined(_16F13125) || \
       defined(_16F13143) || defined(_16F13144) || defined(_16F13145) )

    #error This assembly file is intended to be used only with the PIC16F13145 device family!

#endif

GLOBAL  _start_clb_config
GLOBAL  _end_clb_config

PSECT  clb_config,global,class=STRCODE,delta=2,noexec,optim=

_start_clb_config:
    DW  0x18DC
    DW  0x0802
    DW  0x2030
    DW  0x3E1F
    DW  0x03F0
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x33F8
    DW  0x159F
    DW  0x19F0
    DW  0x3E1F
    DW  0x03F0
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x14DA
    DW  0x0802
    DW  0x203C
    DW  0x3F80
    DW  0x33EC
    DW  0x3E48
    DW  0x08A5
    DW  0x3C5F
    DW  0x03E1
    DW  0x3C1F
    DW  0x21FA
    DW  0x015F
    DW  0x2BEA
    DW  0x3E1F
    DW  0x03FF
    DW  0x3DE5
    DW  0x03E1
    DW  0x3C1F
    DW  0x21FA
    DW  0x195F
    DW  0x2BEA
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x03E1
    DW  0x3C1F
    DW  0x21F0
    DW  0x3E1F
    DW  0x03F0
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x03E1
    DW  0x3DFF
    DW  0x1E60
    DW  0x3E1F
    DW  0x03F0
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x03E1
    DW  0x3C1F
    DW  0x21FA
    DW  0x135F
    DW  0x2BEA
    DW  0x3E1F
    DW  0x03E1
    DW  0x3E1F
    DW  0x03E1
    DW  0x3C1F
    DW  0x21FE
    DW  0x0C02
    DW  0x3847
    DW  0x0408
    DW  0x20BE
    DW  0x1B62
    DW  0x03F8
    DW  0x1406
    DW  0x19F0
    DW  0x3E1F
    DW  0x03F0
    DW  0x3E1F
    DW  0x0CA0
    DW  0x187F
    DW  0x20DE
    DW  0x0802
    DW  0x2030
    DW  0x3E1F
    DW  0x3FEF
    DW  0x0318
    DW  0x3331
    DW  0x3D1F
    DW  0x23F1
    DW  0x3D1F
    DW  0x11F8
    DW  0x3F1F
    DW  0x23E8
    DW  0x3F1F
    DW  0x23F1
    DW  0x3D1F
    DW  0x01E0
    DW  0x0C00
    DW  0x00C0
    DW  0x0000
    DW  0x3800
    DW  0x0002
_end_clb_config:
