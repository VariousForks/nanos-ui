/*******************************************************************************
*   Ledger Blue - Secure firmware
*   (c) 2016, 2017 Ledger
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "os.h"
#include "cx.h"

#include "os_io_seproxyhal.h"
#include "string.h"

#include "bolos_ux_common.h"

#ifdef OS_IO_SEPROXYHAL

const bagl_element_t screen_os_upgrader_static_elements[] = {
    {{BAGL_RECTANGLE, 0x00, 0, 0, 128, 32, 0, 0, BAGL_FILL, 0x000000, 0xFFFFFF,
      0, 0},
     NULL,
     0,
     0,
     0,
     NULL,
     NULL,
     NULL},
    {{BAGL_ICON, 0x00, 35, 9, 9, 14, 0, 0, 0, 0xFFFFFF, 0x000000, 0,
      BAGL_GLYPH_ICON_DOWNLOAD_BADGE},
     NULL,
     0,
     0,
     0,
     NULL,
     NULL,
     NULL},
    {{BAGL_LABELINE, 0x00, 56, 19, 128, 32, 0, 0, 0, 0xFFFFFF, 0,
      BAGL_FONT_OPEN_SANS_REGULAR_11px, 0},
     "Update",
     0,
     0,
     0,
     NULL,
     NULL,
     NULL},
};

void screen_os_upgrader(void) {
    screen_state_init(0);
    G_bolos_ux_context.screen_stack[0].element_arrays[0].element_array =
        screen_os_upgrader_static_elements;
    G_bolos_ux_context.screen_stack[0].element_arrays[0].element_array_count =
        ARRAYLEN(screen_os_upgrader_static_elements);
    G_bolos_ux_context.screen_stack[0].element_arrays_count = 1;

    G_bolos_ux_context.screen_stack[0].exit_code_after_elements_displayed =
        BOLOS_UX_OK;
    screen_display_init(0);
}

#endif // OS_IO_SEPROXYHAL
