
/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** GUIX Component                                                        */
/**                                                                       */
/**   Synergy Simulation Display Management (Display)                     */
/**                                                                       */
/**************************************************************************/
#define GX_SOURCE_CODE

#include "gx_api.h"
#include "gx_display.h"
#include "gx_dave2d_simulation_display_driver.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_dave2d_simulation_display_driver_24xrgb_setup   PORTABLE C      */
/*                                                           6.4.0        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Ting Zhu, Microsoft Corporation                                     */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    Generic 32-bit XRGB color format display driver setup routine.      */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    display                               The display control block     */
/*    aux_data                              Driver-defined auxiliary data */
/*    toggle_function                       Driver-defined screen toggle  */
/*                                            function                    */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    GUIX Internal Code                                                  */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2023     Ting Zhu                 Initial Version 6.4.0         */
/*                                                                        */
/**************************************************************************/
VOID _gx_dave2d_simulation_display_driver_24xrgb_setup(GX_DISPLAY *display, VOID *aux_data,
                                                        VOID (*toggle_function)(struct GX_CANVAS_STRUCT *canvas,
                                                                                GX_RECTANGLE *dirty_area))
{
    _gx_display_driver_24xrgb_setup(display, aux_data, toggle_function);

    display -> gx_display_driver_pixelmap_draw                 = _gx_dave2d_simulation_display_driver_24xrgb_pixelmap_draw;
    display -> gx_display_driver_pixelmap_blend                = _gx_dave2d_simulation_display_driver_24xrgb_pixelmap_blend;
    display -> gx_display_driver_4bit_glyph_draw               = _gx_dave2d_simulation_display_driver_glyph_4bit_draw;
    display -> gx_display_driver_1bit_glyph_draw               = _gx_dave2d_simulation_display_driver_32bpp_glyph_1bit_draw;
    display -> gx_display_driver_8bit_compressed_glyph_draw    = _gx_dave2d_simulation_display_driver_compressed_glyph_8bit_draw;
    display -> gx_display_driver_4bit_compressed_glyph_draw    = _gx_dave2d_simulation_display_driver_compressed_glyph_4bit_draw;
    display -> gx_display_driver_1bit_compressed_glyph_draw    = _gx_dave2d_simulation_display_driver_32bpp_compressed_glyph_1bit_draw;
    display -> gx_display_driver_horizontal_pixelmap_line_draw = _gx_dave2d_simulation_display_driver_32bpp_horizontal_pixelmap_line_draw;
}

