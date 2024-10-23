/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

#ifndef MATRIX_H
#define	MATRIX_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                  Includes                                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "mcc_generated_files/system/system.h"
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                             Macros and defines                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_ROWS          16
#define NUMBER_OF_COLUMNS       16
#define NUMBER_OF_LEDS          ( NUMBER_OF_ROWS*NUMBER_OF_COLUMNS )

 
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                        Typedefs, enums and structs                         //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    uint8_t greenChannel;
    uint8_t redChannel;
    uint8_t blueChannel;
} color_t; 

typedef enum 
{
    CYAN = 0,
    BLUE,
    GREEN,
    YELLOW,
    ORANGE,
    RED,
    PINK,
    PURPLE,
    OCEAN_BLUE,
    LIGHT_BLUE,
    SALMON, 
    SIENNA,
    DARK_GREEN,
    DARK_PINK,
    CHERRY,
    WHITE,
    BLACK
}color_type_t;

const color_t barColors[17] =   {{0, 254, 254}, {0, 0, 255}, {255, 0, 0}, {255, 255, 0},
                                {255, 128, 0}, {0, 255, 0}, {254, 102, 178}, {50, 0, 102},
                                {50, 152, 254}, {0, 52, 102}, {250,128,114},{160,82,44},
                                {0, 102, 40},{152, 0, 76},{127, 216, 127}, {80, 80, 80},
                                {0, 0, 0}};  


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 Public API                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


void Draw_Matrix(int16_t *realNumbers);
void LEDs_OFF(void);


#endif	/* MATRIX_H */